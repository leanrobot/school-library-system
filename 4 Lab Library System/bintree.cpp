//-----------------------------------------------------------------------------
// BINTREE.CPP
// BinTree Class Implementaion
// Author: Magdalena Grzmiel
//-----------------------------------------------------------------------------
// BinTree class: is a representation of binary search tree class with some
// additional functions. Each element of the tree is kept in Node structure
// which kept object NodeData which kept string and other two Node pointers
// which pointed to the left and right child.
//
// Assumptions:
// - the default constructor creates an empty tree
// - the overloading operator<< prints the elements of the tree in inorder
//   traversal
// - creating tree from an array creates a balance tree
// - the elements are inserted in sorted order to the array
// - after putting the elements to the array, the tree is left empty
// - the getHeight method returns number of nodes between the given node and
//   the farthest leaf. For single node the getHeight is 1, for node with
//   one child is 2, when node is not found getHeight is 0.
//   at a leaf is 1, height of a node at the next level is 2, and so on
// - the equal method check not only if the data in the nodes of the two trees
//   are the same but also their structures.
//-----------------------------------------------------------------------------
#include "bintree.h"
#include <iostream>
#include <algorithm>

//-----------------------------------------------------------------------------
// Overloaded output operator << for class BinTree
// writes NodeData to a stream in inorder traversal.
//ostream& operator<<(ostream& output, const BinTree& otherTree) {
//	otherTree.inorderHelper(output, otherTree.root);
//    output << endl;
//    return output;
//}

//-----------------------------------------------------------------------------
// inorderHelper
// Helper method which takes as parameters ostream and Node*
// and writes the node and sub nodes' data in inorder traversal
//void BinTree::inorderHelper(ostream& output, const Node* ptr) const {
//    if (ptr != NULL) {
//        inorderHelper(output, ptr->left);
//        //output << *ptr->print() << " ";
//        inorderHelper(output, ptr->right);
//    }
//}

//-----------------------------------------------------------------------------
// Constructor
BinTree::BinTree() {
    root = NULL;
}

//-----------------------------------------------------------------------------
// Copy constructor
//BinTree::BinTree(const BinTree &otherTree) {
//    root = copy(otherTree.root);
//}

//-----------------------------------------------------------------------------
// Destructor
BinTree::~BinTree() {
    makeEmpty();
}

//-----------------------------------------------------------------------------
// makeEmpty
// Remove every Node from tree
void BinTree::makeEmpty() {
    removeNodes(root);
    root = NULL; // set up the root to NULL
}

//-----------------------------------------------------------------------------
// removesNodes
// Helper method which removes all elements of the BinTree
void BinTree::removeNodes(Node* ptr) {
    if (ptr != NULL) {
        removeNodes(ptr->left);
        removeNodes(ptr->right);
        delete ptr->item;
        delete ptr;
    }
}

//-----------------------------------------------------------------------------
// isEmpty
// Return true if tree is empty, otherwise false
bool BinTree::isEmpty() const {
    return root == NULL;
}

//-----------------------------------------------------------------------------
// Overloaded assignment operator
// Copy otherBinTree to this BinTree.
//BinTree& BinTree::operator=(const BinTree& otherTree) {
//    if (this != &otherTree) {
//        removeNodes(root);
//        root = copy(otherTree.root);
//    }
//
//    return *this;
//}

//-----------------------------------------------------------------------------
// copy
// Helper method which creates a copy of a node and its children
/*
BinTree::Node* BinTree::copy(const Node* otherTree) {
    Node* node;
    if (otherTree == NULL) {
        node = NULL;
    } else {
        node = new Node();
        node->data = new NodeData(*otherTree->data);
        node->left = copy(otherTree->left);
        node->right = copy(otherTree->right);
    }

    return node;
}*/

//-----------------------------------------------------------------------------
// Overloaded equal operator
// Determine if two BinTree are equal
//bool BinTree::operator==(const BinTree& otherTree) const {
//    return compare(root, otherTree.root);
//}

//-----------------------------------------------------------------------------
// Overloaded not equal operator
// Determine if two BinTree are not equal
//bool BinTree::operator!=(const BinTree& otherTree) const {
//    return !compare(root, otherTree.root);
//}

//-----------------------------------------------------------------------------
// compare
// Helper method which compare each node of the BinTree with the
// equivalent node of the other BinTree (checks not only if the data in both
// trees are the same, but also the structures of both trees are the same).
//bool BinTree::compare(Node* thisPtr, const Node* ptr) const {
//    if (thisPtr == NULL || ptr == NULL) { // check if one of the tree is null
//
//        // return true, if both of them are null
//        return thisPtr == NULL && ptr == NULL;
//    }
//
//    return (*thisPtr->data == *ptr->data) && compare(thisPtr->left, ptr->left)
//            && compare(thisPtr->right, ptr->right);
//}

//-----------------------------------------------------------------------------
// Retrieve
// Retrieve a NodeData of a given object and assign found NodeData to the
// pointer ptr which will be pointed to that NodeData if it is found.
// The method should return true if NodeData is found, false otherwise.
bool BinTree::retrieve(const Item& item, Item*& ptr) const {
    
    if (root == NULL) { // if the tree is empty insert new Node to the root
        return false;
        
    } else {        
        Node *current = root;
        bool insert = false;
        
        while (!insert) {
            if (*current->data == *data) { // if the elements already exist in
                return false;              // the tree, do not insert
            }
            
            if (*current->data > *data) {
                if (current->left == NULL) {
                    current->left = new Node();
                    current->left->data = data;
                    insert = true;
                } else {
                    current = current->left;
                }
                
            } else {
                if (current->right == NULL) {
                    current->right = new Node();
                    current->right->data = data;
                    insert = true;
                } else {
                    current = current->right;
                }
            }
        }
    }
    
    return true;
}

}

//-----------------------------------------------------------------------------
// findNode
// Helper method which takes as parameters pointer to the root of the tree and
// NodeData object and return the Node which contains the given data
BinTree::Node* BinTree::findNode(Node* ptr, const NodeData& data) const {
    if (ptr != NULL) { //check if the tree is not empty
        if (*ptr->data == data) { //check the root
            return ptr;
        }

        Node* temp = findNode(ptr->left, data); //check the left subBinTree and
                                                //assign it to the temp pointer
        if (temp == NULL) { // if return value from left subtree is NULL
            return findNode(ptr->right, data); // check right subBinTree
        }

        return temp;
    }

    return NULL;
}
//-----------------------------------------------------------------------------
// getNodeHeight
// Returns the height of the given NodeData if found, 0 otherwise.
int BinTree::getHeight(const NodeData& data) const {

    Node* ptr = findNode(root, data); // find the NodeData with given value and
                                      // assign it to ptr pointer

    return getNodeHeight(ptr); // call the helper method for the found Node
}

//-----------------------------------------------------------------------------
// getHeightHelper
// Helper method which takes as parameters Node with the given value and
// returns the height of that Nodes
int BinTree::getNodeHeight(const Node* ptr) const {
    if (ptr == NULL) {
        return 0;
    } else {
        return 1 + std::max(getNodeHeight(ptr->left),
                getNodeHeight(ptr->right));
    }
}

//-----------------------------------------------------------------------------
// Insert
// Insert the NodeData object to the tree only if the elements was not
// found in the tree.
// Return true if the element was inserted successful, false otherwise.
bool BinTree::insert(NodeData* data) {
    if (data == NULL) { //check if the data is not NULL
        return false;
    }
    if (root == NULL) { // if the tree is empty insert new Node to the root
        root = new Node(); // create new Node
        root->data = data; // insert NodeData data to the Node
        return true;

    } else { // otherwise traverse the tree to find the right spot
             // to insert the NodeData

        Node *current = root;
        bool insert = false;

        while (!insert) {
            if (*current->data == *data) { // if the elements already exist in
                return false;              // the tree, do not insert
            }

            if (*current->data > *data) {
                if (current->left == NULL) {
                    current->left = new Node();
                    current->left->data = data;
                    insert = true;
                } else {
                    current = current->left;
                }

            } else {
                if (current->right == NULL) {
                    current->right = new Node();
                    current->right->data = data;
                    insert = true;
                } else {
                    current = current->right;
                }
            }
        }
    }

    return true;
}

//-----------------------------------------------------------------------------
// DisplaySideways
// Display the tree sideways
void BinTree::displaySideways() const {
    sideways(root, 0);
}

//-----------------------------------------------------------------------------
// sideways
// Helper method for displaySideways()
/*
void BinTree::sideways(Node* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl; // display information of object
        sideways(current->left, level);
    }
}
 */

//-----------------------------------------------------------------------------
// bstreeToArray
// Fills an array of NodeData* with the NodeData by using inorder traversal
// of the tree and remove Nodes from tree
void BinTree::bstreeToArray(NodeData* array[]) {
    putToArray(array, root, 0);
    root = NULL;
}

//-----------------------------------------------------------------------------
// putToArray
// Helper method which put the elements (NodeData objects) from the tree to
// the array using inorder traversal
int BinTree::putToArray(NodeData* array[], Node* ptr, int startIndex) {
    if (ptr == NULL) {
        return startIndex;
    }

    // calculate the index of the array to which the element will be inserted
    // in sorted order
    startIndex = putToArray(array, ptr->left, startIndex);
    array[startIndex++] = ptr->data;
    startIndex = putToArray(array, ptr->right, startIndex);

    delete ptr; // delete pointer to make the tree empty after inserting it to
                // the array

    return startIndex;
}

//-----------------------------------------------------------------------------
// arratToBSTree
// Build a balance BinTree from a sorted array.
// Leaving the array filled with NULLs.
void BinTree::arrayToBSTree(NodeData* array[]) {
    int low = 0;
    int high = lastFilledIndex(array);
    buildBalancedTree(array, low, high);
}

//-----------------------------------------------------------------------------
// buildBalancedTree
// Helper method which build balanced tree from elements from sorted array
void BinTree::buildBalancedTree(NodeData* array[], int low, int high) {
    if (low > high) {
        return;
    }

    int mid = (low + high) / 2; // calculate the index of the array from which
                                // the element will be inserted into the tree
    insert(array[mid]);
    array[mid] = NULL;
    buildBalancedTree(array, low, mid - 1);
    buildBalancedTree(array, mid + 1, high);
}

//-----------------------------------------------------------------------------
// lastFilledIndex
// Helper method which calculate how many elements in the array contain
// NodeData objects
int BinTree::lastFilledIndex(NodeData* array[]) {
    int i = 0;
    while (array[i++] != NULL);
    return i - 2;
}

/*
void BinTree:: findNthSmallest(int target){
	Node * temp = NULL;
	bool find = false;
	findNthSmallest(find, root, temp, 0, target);
	if (temp == NULL){
		cout<< "Invalid";
	}
	else{
		cout<< *temp->data;
	}
}
 */

int BinTree:: findNthSmallest(bool find, Node*ptr, Node*& targetptr, int startIndex, int target) {
    if (ptr == NULL && !find) {
        return startIndex;
    }

   if (!find){
    startIndex = findNthSmallest(find, ptr->left, targetptr, startIndex, target);
    cout<<"left"<<endl;
   }
   startIndex++;
   cout<<"index "<<startIndex<<endl;
   if (startIndex == target && !find){
	   targetptr = ptr;
	   find= true;
   }
   if (!find){
    startIndex = findNthSmallest( find, ptr->right, targetptr, startIndex, target);
    cout<<"right"<<endl;
   }

    return startIndex;
}
