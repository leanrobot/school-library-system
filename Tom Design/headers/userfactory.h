
//-----------------------------------------------------------------------------
// class UserFactory
//
// Factory class responsible for building users that will be patrons of the
// library system.
//
// Assumptions:
//  -- the inputted raw data structure must be formatted correctly
//-----------------------------------------------------------------------------

#ifndef USERFACTORY_H
#define USERFACTORY_H
#include "user.h"
#include <map>

class UserFactory {
public:
	UserFactory(); // Constructor
	~UserFactory(); // Destructor
    User* createUser(string data); // Creates the user
    			// from the raw data.
private:
    map<int, User*> users; // holds the available 
    				// user types to be created.
};