//
//  itemcollection.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/5/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "itemcollection.h"
#include <algorithm>

/*
ItemCollection::ItemCollection() {
    //vector is instantiated automatically.
}

ItemCollection::~ItemCollection() {
    items.clear();
    //vector is destroyed automatically
}

bool ItemCollection::insert(Item* item) {
    
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

Item* ItemCollection::retrieve(Item* item) {

    std::vector<Item*>::iterator iter;
    for(iter=items.begin(); iter != items.end(); iter++) {
        if(*item == **iter) return *iter;
    }
    return NULL;
}

Item* ItemCollection::retrieve(int i) {
    return items[i];
}

int ItemCollection::size() const {
    return items.size();
}
*/

ItemCollection::ItemCollection() {
    root = NULL;
}

ItemCollection:: ~ItemCollection(){
    makeEmpty();
}


void ItemCollection:: makeEmpty() {
    removeNodes(root);
    root = NULL; // set up the root to NULL
}

void ItemCollection::removeNodes(Node* ptr) {
    if (ptr != NULL) {
        removeNodes(ptr->left);
        removeNodes(ptr->right);
        delete ptr->itemData;
        delete ptr;
    }
}

Item* ItemCollection:: retrieve(const Item* item)const{
    if (item == NULL){
        return NULL;
    }
   
    Node* current = root;
    Item * findItem = NULL;
   
    while(current != NULL && !(*findItem == *item)){
       if (*current->itemData == *item){
           findItem = current->itemData;
       }
       else if (*current->itemData < *item){
           current = current->right;
       }else{
           current = current->left;
       }
    }
    
    return findItem;
}


int ItemCollection:: getHeight()const{
    return getHeightNode(root);
}
int ItemCollection:: getHeightNode(Node* ptr)const{
    if (ptr == NULL){
        return 0;
    }
    else{
        return 1+ std::max(getHeightNode(ptr->left),
                       getHeightNode(ptr->right));
    }
}


bool ItemCollection:: insert(Item* item){
    
    insertHelper(root,item);
    return true;
}

void ItemCollection:: insertHelper(Node*& current, Item* item){
    
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

void ItemCollection:: leftLeft(Node*& k2) {
    Node* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( getHeightNode(k2->left), getHeightNode(k2->right) ) + 1;
    k1->height = max( getHeightNode(k1->left), k2->height ) + 1;
    k2 = k1;
}

void ItemCollection::rightRight(Node*&k2){
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( getHeightNode(k2->left), getHeightNode(k2->right) ) + 1;
    k1->height = max( getHeightNode(k1->right), k2->height ) + 1;
    k2 = k1;
    
}
void ItemCollection::leftRight(Node*&k3){
    rightRight(k3->left);
    leftLeft(k3);
}
void ItemCollection::rightLeft(Node*&k3){
    leftLeft (k3->right);
    rightRight(k3);
    
}

void ItemCollection:: print()const{
    printHelper (root);
}

void ItemCollection::printHelper(Node*ptr)const{
    if (ptr != NULL) {
        printHelper(ptr->left);
        ptr->itemData->print();
        printHelper(ptr->right);
    }
}
