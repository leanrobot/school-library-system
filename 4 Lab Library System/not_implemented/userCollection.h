//-----------------------------------------------------------------------------
// User Collection class: a collection that stores library patrons. Includes 
// the following features:
//  -- Add users to the library
//  -- Display a list of library patrons
//  -- Retrieve a specific user
//
// Assumptions:
//  -- Assumes there is not a need to remove a user from the list
//-----------------------------------------------------------------------------

#ifndef USERCOLLECTION_H
#define USERCOLLECTION_H
#include "user.h"
using namespace std;

class UserCollection {
public:
    // insert
    // Inserts a user
    bool insert(User*);

    // display
    // Display the list of user
    void display( ) const;
    
    // retrive
    // Retrives user's object
    bool retrieve(int, User*&) const;
    
private:
    struct Node {
      User* user;        // pointer to user object
      Node* left;        // left subtree pointer
      Node* right;       // right subtree pointer
    };
    
    Node* root;          // root of the tree

};

#endif
