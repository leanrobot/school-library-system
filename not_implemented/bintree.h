//-----------------------------------------------------------------------------
// BINTREE.H
// BinTree Class
// Author: Magdalena Grzmiel
//-----------------------------------------------------------------------------
// BinTree class: is a representation of binary search tree class with some
// additional functions. Each element of the tree is kept in Node structure
// which kept object Item which kept string and other two Node pointers
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

#ifndef BINTREE_H_
#define BINTREE_H_
#include "item.h"

class BinTree {
    //-------------------------------------------------------------------------
    // Overloaded output operator << for class BinTree
    // writes Item to a stream in inorder traversal.
    friend ostream& operator<< (ostream &output, const BinTree &otherTree);

public:
    //-------------------------------------------------------------------------
    // Constructor
    BinTree();

    //-------------------------------------------------------------------------
    // Copy constructor
    //BinTree(const BinTree & otherTree);

    //-------------------------------------------------------------------------
    // Destructor
    ~BinTree();

    //-------------------------------------------------------------------------
    // isEmpty()
    // Return true if tree is empty, otherwise false.
    bool isEmpty() const;

    //-------------------------------------------------------------------------
    // makeEmpty()
    // Remove every Node from tree.
    void makeEmpty();

    //-------------------------------------------------------------------------
    // Overloaded assignment operator
    // Copy otherBinTree to this BinTree.
    // BinTree& operator=(const BinTree& otherBinTree);

    //-------------------------------------------------------------------------
    // Overloaded equal operator
    // Determine if two BinTrees are equal.
    //bool operator==(const BinTree& otherBinTree) const;

    //-------------------------------------------------------------------------
    // Overloaded not equal operator
    // Determine if two BinTree are not equal.
    // bool operator!=(const BinTree& otherBinTree) const;

    //-------------------------------------------------------------------------
    // Insert
    // Insert the Item object to the tree only if the elements was not
    // found in that tree.
    // Return true if the element was inserted successful, false otherwise.
    bool insert(Item* item);

    //-------------------------------------------------------------------------
    // Retrieve
    // Retrieve a Item of a given object and assign found Item to the
    // pointer ptr which will be pointed to that Item if it is find.
    // The method should return true if Item is found, false otherwise.
    bool retrieve(const Item& item, Item*& ptr) const;


    //-------------------------------------------------------------------------
    // DisplaySideways
    // Display the tree sideways.
    //void displaySideways() const;

    //-------------------------------------------------------------------------
    // getHeight
    // Returns the height of the given Item if found, 0 otherwise.
    //int getHeight(const Item& item) const;

    //-------------------------------------------------------------------------
    // bstreeToArray
    // Fills an array of Item* with the Item by using inorder traversal
    // of the tree and remove Nodes from tree
    //void bstreeToArray(Item* array[]);

    //-------------------------------------------------------------------------
    // arratToBSTree
    // Build a balance BinTree from a sorted array.
    // Leaving the array filled with NULLs.
    //void arrayToBSTree(Item* array[]);
    //void findNthSmallest(int i);

private:
    struct Node {
        Item* item; // pointer to data object
        Node* left;     // pointer to the left subtree
        Node* right;    // pointer to the right subtree
    };
    Node* root;         // root of the tree
    
    Node* findParent(const NodeData* data) const;

    //int findNthSmallest(bool find, Node*ptr, Node*& targetPtr, int startIndex, int target);

    //-------------------------------------------------------------------------
    // inorderHelper
    // Helper method which takes as parameters ostream and Node*
    // and writes the node and sub nodes' data in inorder traversal
    //void inorderHelper(ostream& output, const Node* ptr) const;

    //-------------------------------------------------------------------------
    // sideways
    // Helper method for displaySideways()
    //void sideways(Node* current, int level) const;

    //-------------------------------------------------------------------------
    // copy
    // Helper method which creates a copy of a node and its children
    // Node* copy(const Node* otherTree);

    //-------------------------------------------------------------------------
    // removesNodes
    // Helper method which removes all nodes from the BinTree
    void removeNodes(Node* ptr);

    //-------------------------------------------------------------------------
    // compare
    // Helper method which compare each node of the BinTree with the
    // equivalent node of the other BinTree
    // bool compare(Node* thisPtr, const Node* ptr) const;

    //-------------------------------------------------------------------------
    // getNodeHeight
    // Helper method which takes as parameters Node with the given value and
    // returns the height of that Node
    // int getNodeHeight(const Node* ptr) const;

    //-------------------------------------------------------------------------
    // findNode
    // Helper method which takes as parameters pointer to the root of the tree
    // and Item object and return the Node which contains the given data
    Node* findNode(Node*ptr, const Item& data) const;

    //-------------------------------------------------------------------------
    // putToArray
    // Helper method which put the elements (Item objects) from the tree to
    // the array using inorder traversal
    //int putToArray(Item* array[], Node* root, int startIndex);

    //------------------------------------------------------------------------
    // lastFilledIndex
    // Helper method which calculate how many elements in the array contain
    // Item objects
    //int lastFilledIndex(Item* array[]);

    //-------------------------------------------------------------------------
    // buildBalancedTree
    // Helper method which build balanced tree from elements from array
    //void buildBalancedTree(Item* array[], int low, int high);
};

#endif /* BINTREE_H_ */
