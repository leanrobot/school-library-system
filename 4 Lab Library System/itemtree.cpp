//
//  ItemTree.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/5/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "itemtree.h"
#include <algorithm>

/*
ItemTree::ItemTree() {
    //vector is instantiated automatically.
}

ItemTree::~ItemTree() {
    items.clear();
    //vector is destroyed automatically
}

bool ItemTree::insert(Item* item) {
    
    std::vector<Item*>::iterator iter = items.begin();
    if(items.size() > 0) {
        for(; iter != items.end() && *(*iter) < *item ; iter++) {
        }
        items.insert(iter, item);
    }
    else {
        items.push_back(item);
    }
    
    return true;
}

Item* ItemTree::retrieve(Item* item) {

    std::vector<Item*>::iterator iter;
    for(iter=items.begin(); iter != items.end(); iter++) {
        if(*item == **iter) return *iter;
    }
    return NULL;
}

Item* ItemTree::retrieve(int i) {
    return items[i];
}

int ItemTree::size() const {
    return items.size();
}
*/

ItemTree::ItemTree() {
    root = NULL;
}

ItemTree:: ~ItemTree(){
    makeEmpty();
}


void ItemTree:: makeEmpty() {
    removeNodes(root);
    root = NULL; // set up the root to NULL
}

void ItemTree::removeNodes(Node* ptr) {
    if (ptr != NULL) {
        removeNodes(ptr->left);
        removeNodes(ptr->right);
        delete ptr->itemData;
        delete ptr;
    }
}

Item* ItemTree:: retrieve(const Item* item)const{
    if (item == NULL){
        return NULL;
    }
   
    Node* current = root;
    Item* findItem = NULL;
   
    /*current != NULL && (findItem == NULL || findItem!= item) TODO*/
    while(current != NULL /*|| !(findItem != NULL && *findItem == *item)*/){
       if (*current->itemData == *item){
           findItem = current->itemData;
           current = NULL;
       }
       else if (*current->itemData < *item){
           current = current->right;
       }
       else {
           current = current->left;
       }
    }
    
    return findItem;
}


int ItemTree:: getHeight()const{
    return getHeightNode(root);
}
int ItemTree:: getHeightNode(Node* ptr)const{
    if (ptr == NULL){
        return 0;
    }
    else{
        return 1+ std::max(getHeightNode(ptr->left),
                       getHeightNode(ptr->right));
    }
}


bool ItemTree:: insert(Item* item){
    
    insertHelper(root,item);
    return true;
}

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
    
    current->height = max(getHeightNode(current->left ),
                          getHeightNode(current->right) ) + 1;
}

void ItemTree:: leftLeft(Node*& k2) {
    Node* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( getHeightNode(k2->left), getHeightNode(k2->right) ) + 1;
    k1->height = max( getHeightNode(k1->left), k2->height ) + 1;
    k2 = k1;
}

void ItemTree::rightRight(Node*&k2){
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( getHeightNode(k2->left), getHeightNode(k2->right) ) + 1;
    k1->height = max( getHeightNode(k1->right), k2->height ) + 1;
    k2 = k1;
    
}
void ItemTree::leftRight(Node*&k3){
    rightRight(k3->left);
    leftLeft(k3);
}
void ItemTree::rightLeft(Node*&k3){
    leftLeft (k3->right);
    rightRight(k3);
    
}

void ItemTree:: print()const{
    if(root != NULL) {
        Item* item = root->itemData;
        item->printHeader();
    }
    printHelper (root);
}

void ItemTree::printHelper(Node*ptr)const{
    if (ptr != NULL) {
        printHelper(ptr->left);
        ptr->itemData->print();
        printHelper(ptr->right);
    }
}
