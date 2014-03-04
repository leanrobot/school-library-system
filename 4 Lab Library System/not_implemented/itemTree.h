//-----------------------------------------------------------------------------
// ItemTree class: is a binary search tree ADT that contains item objects.
// Includes the following features:
//  -- Add item to the library
//  -- Display all items in the tree
//  -- Retrieve a specific item
//
// Assumptions:
//  -- item class is assumed to exist elsewhere
//  -- assumes valid item input
//-----------------------------------------------------------------------------

#ifndef ITEMTREE_H
#define ITEMTREE_H

#include "item.h"
#include <string>
#include <iostream>
using namespace std;

class ItemTree {

public:

	// Constructor
    ItemTree();

    // Destructor
    ~ItemTree();

    // Insert
    // Insert item into the tree
    bool insert(Item*);

    // Retrieve
    // Retrive item from tree
    bool retrieve(const Item&, Item*&) const;

    //display the entire tree
    void display()const;

private:

	struct Node {
		Item* item;     // pointer to item object
		Node* left;     // left subtree pointer
		Node* right;    // right subtree pointer
	};

	Node* root;        // root of the tree
   
	//helper method to retrieve an item from the hashtable using a string
	//which contains searching criteria of an Item
	bool retrieve(string, Item*&) const;
};

#endif