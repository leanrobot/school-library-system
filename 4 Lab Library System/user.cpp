//-----------------------------------------------------------------------------
// USER.CPP
// User class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// User class: a class to represent the library patrons. Includes the following
// features:
//  -- Get the patron's unique User ID
//  -- Get the patron's last name
//  -- Get the patron's first name
//  -- Get the transaction history
//  -- Update the patron's last name
//  -- Update the patron's first name
//  -- Compare
//
// Assumptions:
//  -- Assumes User IDs will not change once assigned
//-----------------------------------------------------------------------------

#include "user.h"

/*-----------------------------------------------------------------------------
===== Constructor
 Descripton: Constructor for User class.
------------------------------------------------------------------------------*/
User::User(int id, string name) {
    this->userId = id;
    this->name = name;
    this->userHistory = new History;
}

/*-----------------------------------------------------------------------------
 ===== Destructor
------------------------------------------------------------------------------*/
User:: ~User(){
    delete userHistory;
}

/*-----------------------------------------------------------------------------
 ===== Get ID
 Descripton: Retrieves the user id.
 Pre:
 Post: Returns the user id.
-----------------------------------------------------------------------------*/
int User::getID() const {
    return userId;
}

/*-----------------------------------------------------------------------------
 ===== Get History
 Descripton: Retrive the user's history object.
 Pre:
 Post: Returns the user's history object.
------------------------------------------------------------------------------*/
History* User:: getUserHistory() const{
    return userHistory;
}


/*-----------------------------------------------------------------------------
 ===== Get Name
 Descripton: retrive the user's name.
 Pre:
 Post: Retrive the user's name.
-----------------------------------------------------------------------------*/
string User::getName() const {
    return name;
}

/*-----------------------------------------------------------------------------
 ===== Set Name
 Descripton: sets the user's name.
-----------------------------------------------------------------------------*/
void User:: setName(string newName){
    name = newName;
}
