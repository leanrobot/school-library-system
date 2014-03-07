//
//  ItemTree.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/5/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef ____Lab_Library_System__ItemTree__
#define ____Lab_Library_System__ItemTree__

#include <iostream>
//#include <vector>
#include "item.h"

class ItemTree {
public:
    ItemTree();
   
    ~ItemTree();
    
    bool insert(Item* item);
    
    Item* retrieve(const Item* item)const;
    
    int getHeight()const;
    
    void print()const;
    
    void makeEmpty();
    
    //Item* retrieve(int index);
    //int size() const;
private:
    //vector<Item*> items;
    struct Node{
        Item* itemData;
        Node* left;
        Node* right;
        int height;
    };
    Node* root;
    
    void insertHelper(Node*& current, Item* item);
    
    void printHelper(Node* ptr) const;
    
    int getHeightNode(Node* ptr)const;
    
    void leftLeft(Node*& k2);
    
    void rightRight(Node*&k2);
    
    void leftRight(Node*&k3);
    
    void rightLeft(Node*&k3);
    
    void removeNodes(Node* ptr);
    
};

#endif /* defined(____Lab_Library_System__ItemTree__) */
