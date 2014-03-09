//
//  userfactory.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/4/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "userfactory.h"

bool UserFactory::instanceFlag = false;
UserFactory* UserFactory::_instance = NULL;

UserFactory::UserFactory() {}

UserFactory* UserFactory::instance() {
    if(!instanceFlag) {
        instanceFlag = true;
        _instance = new UserFactory;
    }
    return _instance;
}

UserFactory::~UserFactory() {
    if(instanceFlag) {
        instanceFlag = false;
        _instance = NULL;
    }
}


User* UserFactory::createUser(istream& input) {
    int id;
    string name;//, firstName, lastName;
    
    if(input.eof()) return NULL;
    input >> id;
    input.get();
    if(input.eof()) return NULL;
    getline(input, name);
    
    User* u = new User(id, name);
    return u;
}