//
//  userfactory.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/4/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef ____Lab_Library_System__userfactory__
#define ____Lab_Library_System__userfactory__

#include <iostream>
#include <fstream>

#include "user.h"

class UserFactory {
public:
    static UserFactory* instance(); // Singleton controlled creation function
    User* createUser(istream&);
private:
    UserFactory(); // private to prevent singleton creation.
    //declared, but not implemented, to prevent singleton cloning.
    UserFactory(UserFactory const&);
    void operator=(UserFactory const&);
    
};

#endif /* defined(____Lab_Library_System__userfactory__) */
