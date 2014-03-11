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
 ===== Destructor
 Descripton:
 Pre:
 Post:
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
History* User:: getHistory() const{
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
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
void User:: setName(string newName){
    name = newName;
}
