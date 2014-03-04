//
//  integer.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/3/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "integer.h"

Integer::Integer(int i) {
    data = i;
}

char Integer::hash() const {
    return 'I';
}