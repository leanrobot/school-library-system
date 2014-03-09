#include "user.h"

/*-----------------------------------------------------------------------------
===== Constructor
 Descripton: Constructor for User class.
 Pre:
 Post:
------------------------------------------------------------------------------*/
User::User(int id, string name) {
    this->userId = id;
    this->name = name;
    this->userHistory = new History;
}

/*-----------------------------------------------------------------------------
 ===== Get ID
 Descripton: Retrieves the user id.
 Pre:
 Post: returns the user id.
 -----------------------------------------------------------------------------*/
int User::getID() const {
    return userId;
}

/*-----------------------------------------------------------------------------
 ===== Destructor
 Descripton:
 Pre:
 Post:
------------------------------------------------------------------------------*/
User:: ~User(){
    delete userHistory;
}

/*-----------------------------------------------------------------------------
 ===== Get History
 Descripton: returns the user's history object.
 Pre:
 Post:
 ------------------------------------------------------------------------------*/
History* User:: getHistory(){
    return userHistory;
}


/*-----------------------------------------------------------------------------
 ===== Get Name
 Descripton: returns the user's name.
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
string User::getName() const {
    return name;
}

/*-----------------------------------------------------------------------------
 ===== Set Name
 Descripton: sets the user's name.
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
void User:: setName(string newName){
    name = newName;
}