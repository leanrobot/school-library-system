//-----------------------------------------------------------------------------
// ITEMTREE.H
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

#ifndef ITEMTREE_H
#define ITEMTREE_H
#include <iostream>
#include "item.h"

class ItemTree {
public:
    // Constructor
    ItemTree();
    
    // Destructor
    ~ItemTree();
    
    // Insert
    // Insert the Item object to the tree only if the elements was not
    // found in that tree.
    void insert(Item* item);
    
    // Retrieve
    // Retrieve a Item of a given object and return pointer on it
    // if it is found.
    // The method should return pointer to found Item
    // or NULL if the item does not appear in the tree.
    Item* retrieve(const Item* item)const;
    
    
    // getHeight
    // Returns the height of the given Item if found, 0 otherwise.
    int getHeight()const;
    
    // print
    // Prints all items from the tree in sorted order.
    void print()const;
    
    // makeEmpty()
    // Remove every Node from tree.
    void makeEmpty();
    
private:
    struct Node{
        Item* itemData; // pointer to Item object
        Node* left;     // pointer to the left children
        Node* right;    // pointer to the right children
        int height;     // height of the given node
    };
    Node* root;         // root of the tree
    
    
    // inorderHelper
    // Helper method used to insert new Item to the tree
    void insertHelper(Node*& current, Item* item);
    
    // printHelper
    // Prints each Item from the tree using inorder traversal
    void printHelper(Node* ptr) const;
    
    // getNodeHeight
    // Helper method which takes as parameters Node with the given value and
    // returns the height of that Node
    int getHeightNode(Node* ptr)const;
    
    // leftLeft
    // LeftLeft rotation to keep the tree balanced
    void leftLeft(Node*& k2);
    
    // rightRight
    // RightRight rotation to keep the tree balanced
    void rightRight(Node*& k2);
    
    // leftRight
    // LeftRight rotation to keep the tree balanced
    void leftRight(Node*& k3);
    
    // rightLeft
    // RightLeft rotation to keep the tree balanced
    void rightLeft(Node*& k3);
    
    // removesNodes
    // Helper method which removes all nodes from the ItemTree
    void removeNodes(Node* ptr);
    
};

#endif /*ITEMTREE_H*/
