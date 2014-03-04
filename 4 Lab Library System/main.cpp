//
//  main.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/2/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//
#include "integer.h"
#include "hashtable.h"
#include <iostream>

using namespace std;
int main() {
    
    HashTable ht;
    
    Integer d(1234);

    cout << "add and retrieve test: ";
    
    ht.add(d.hash(), d);
    
    Hashable* h = ht.get(d.hash());
    Integer* down = dynamic_cast<Integer*>(h);
    
    if(h!=NULL&&down!=NULL&&down->data == d.data) cout << "success\n";
    else cout << "failure\n";
    
    
    ht.remove(d.hash());
    
    cout << "item removal: ";
    if(ht.get(d.hash()) == NULL) cout << "success\n";
    else cout << "failure\n";
    
    return 0;
}