//
//  hashable.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/2/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef __HASHABLE_H
#define __HASHABLE_H

class Hashable {
public:
    virtual char hash() const = 0;
};

#endif /* __HASHABLE_H */
