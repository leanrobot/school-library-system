//-----------------------------------------------------------------------------
// ITEMTREE.CPP
// ItemTree Class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// ItemTree class: is a AVL tree class. Each element of the tree is kept in
// Node structure which kept object Item, the height and two Node pointers
// which pointed to the left and right child.
//
// Assumptions:
// -- the default constructor creates an empty tree
// -- after insertin a new object to the tree, the tree stays balance
// -- the elements are inserted in sorted order to the tree
// -- the getHeight method returns number of nodes between the given node and
//    the farthest leaf
//    at a leaf is 1, height of a node at the next level is 2, and so on
// -- the retrive method returns pointer to the found item
// -- the print method, prints the items in inorder traversal
//-----------------------------------------------------------------------------
#include "itemtree.h"
#include <algorithm>

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Create an empty tree
 ----------------------------------------------------------------------------*/
ItemTree::ItemTree() {
    root = NULL;
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton:
 Pre:
 Post: The tree is deallocated.
 ----------------------------------------------------------------------------*/
ItemTree:: ~ItemTree(){
    makeEmpty();
}

/*---------------------------------------------------------------------------
 ===== makeEmpty
 Descripton: Remove every Node from tree.
----------------------------------------------------------------------------*/
void ItemTree:: makeEmpty() {
    removeNodes(root);
    root = NULL;
}

/*---------------------------------------------------------------------------
 ===== removeNodes
 Descripton: Helper method which removes all elements of the ItemTree
----------------------------------------------------------------------------*/
void ItemTree::removeNodes(Node* ptr) {
    if (ptr != NULL) {
        removeNodes(ptr->left);
        removeNodes(ptr->right);
        delete ptr->itemData;
        delete ptr;
    }
}

/*---------------------------------------------------------------------------
 ===== retrive
 Descripton: Retrieve the ItemTree to check if the given Item is found in the 
 tree.
 Pre:
 Post: Returns pointer to the found Item or NULL if the Item does not appear
 in the tree
 ----------------------------------------------------------------------------*/
Item* ItemTree:: retrieve(const Item* item)const{
    // check if the given Item is not a NULL
    if (item == NULL){
        return NULL;
    }
    
    Node* current = root;
  
    // retrive the tree to find the given Item,
    while(current != NULL){
        if (*current->itemData == *item){
            // if found, return pointer to that item
            return current->itemData;
        }
        else if (*current->itemData < *item){
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    
    // otherwise return NULL
    return NULL;
}

/*---------------------------------------------------------------------------
 ===== getHeight
 Descripton: Calculate the height of the given Node.
 Pre:
 Post: Returns the height of the given Item if found, 0 otherwise.
 ----------------------------------------------------------------------------*/
int ItemTree:: getHeight()const{
    return getHeightNode(root);
}

/*---------------------------------------------------------------------------
 ===== getHeightNode
 Descripton: Helper method to calculate to the height of the given Node.
 Pre:
 Post: Returns the height of the given Item if found, 0 otherwise.
 ----------------------------------------------------------------------------*/
int ItemTree:: getHeightNode(Node* ptr)const{
    if (ptr == NULL){
        return 0;
    }
    else{
        return 1+ std::max(getHeightNode(ptr->left),
                           getHeightNode(ptr->right));
    }
}

/*---------------------------------------------------------------------------
 ===== insert
 Descripton: Insert the Item object to the tree only if the elements was not
 found in that tree. The tree stays balanced after inserting a new Item.
----------------------------------------------------------------------------*/
void ItemTree:: insert(Item* item){
    insertHelper(root,item);
}

/*---------------------------------------------------------------------------
 ===== insertHelper
 Descripton: Helper method to insert Item in the Tree.
----------------------------------------------------------------------------*/
void ItemTree:: insertHelper(Node*& current, Item* item){
    
    if (current == NULL){
        // allocates memory for Nodedata, sets left/right pointers to NULL
        current = new Node();
        current->itemData = item;
        current->left = NULL;
        current->right = NULL;
        
    // insert into left subtree
    }else if (*item < *current->itemData) {
        insertHelper(current->left, item);
        if (getHeightNode(current->left) - getHeightNode(current->right) == 2) {
            if (*item < *current->left->itemData)
                leftLeft(current);
            else
                leftRight(current);
        }
    }
    
    // insert into right subtree
    else if (*item > *current->itemData) {
        insertHelper(current->right, item);
        if (getHeightNode(current->right) - getHeightNode(current->left) == 2) {
            if (*item > *current->right->itemData)
                rightRight(current);
            else
                rightLeft(current);
        }
    }
    
    // duplicate, do nothing, change as needed
    else
        ;
    
    // calculate the height of the node
    current->height = max(getHeightNode(current->left ),
                          getHeightNode(current->right) ) + 1;
}

/*---------------------------------------------------------------------------
 ===== leftLeft
 Descripton: Helper method to keep tree balanced after inserting a new Item
----------------------------------------------------------------------------*/
void ItemTree:: leftLeft(Node*& k2) {
    Node* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( getHeightNode(k2->left), getHeightNode(k2->right) ) + 1;
    k1->height = max( getHeightNode(k1->left), k2->height ) + 1;
    k2 = k1;
}

/*---------------------------------------------------------------------------
 ===== rightLeft
 Descripton: Helper method to keep tree balanced after inserting a new Item
----------------------------------------------------------------------------*/
void ItemTree::rightRight(Node*&k2){
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( getHeightNode(k2->left), getHeightNode(k2->right) ) + 1;
    k1->height = max( getHeightNode(k1->right), k2->height ) + 1;
    k2 = k1;
    
}

/*---------------------------------------------------------------------------
 ===== leftRight
 Descripton: Helper method to keep tree balanced after inserting a new Item
----------------------------------------------------------------------------*/
void ItemTree::leftRight(Node*&k3){
    rightRight(k3->left);
    leftLeft(k3);
}

/*---------------------------------------------------------------------------
 ===== rightLeft
 Descripton: Helper method to keep tree balanced after inserting a new Item
----------------------------------------------------------------------------*/
void ItemTree::rightLeft(Node*&k3){
    leftLeft (k3->right);
    rightRight(k3);
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Prints all items from the tree in sorted order.
----------------------------------------------------------------------------*/
void ItemTree:: print()const{
    if(root != NULL) {
        Item* item = root->itemData;
        item->printHeader();
    }
    printHelper (root);
}

/*---------------------------------------------------------------------------
 ===== printHelper
 Descripton: Prints each Item from the tree using inorder traversal.
----------------------------------------------------------------------------*/
void ItemTree::printHelper(Node*ptr)const{
    if (ptr != NULL) {
        printHelper(ptr->left);
        ptr->itemData->print();
        printHelper(ptr->right);
    }
}
