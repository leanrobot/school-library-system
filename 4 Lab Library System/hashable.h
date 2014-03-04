//
//  hashable.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/2/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef ____Lab_Library_System__hashable__
#define ____Lab_Library_System__hashable__

class Hashable {
public:
    virtual char hash() const = 0;
};

#endif /* defined(____Lab_Library_System__hashable__) */
