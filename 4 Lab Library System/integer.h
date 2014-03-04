//
//  integer.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/3/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef ____Lab_Library_System__integer__
#define ____Lab_Library_System__integer__

#include <iostream>
#include "hashable.h"

class Integer : public Hashable {
public:
    Integer(int i);
    
    char hash() const;
    int data;
};

#endif /* defined(____Lab_Library_System__integer__) */
