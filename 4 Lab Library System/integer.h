//
//  integer.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/3/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef __INTEGER_H
#define __INTEGER_H

#include <iostream>
#include "hashable.h"

class Integer : public Hashable {
public:
    Integer(int i);
    
    char hash() const;
    int data;
};

#endif /* __INTEGER_H */
