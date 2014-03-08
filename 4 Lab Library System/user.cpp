#include "user.h"

User::User(int id, string name) {
    this->userId = id;
    this->name = name;
    userHistory = new History;
}

int User::getID() const {
    return userId;
}

User:: ~User(){
    delete userHistory;
}

History* User:: getHistory(){
    return userHistory;
}



string User::getName() const {
    return name;
}

void User:: setName(string newName){
    name = newName;
}

/*void User::setFirstName(string firstName) {
    this->firstName = firstName;
}

string User::getLastName() const {
    return lastName;
}
void User::setLastName(string lastName) {
    this->lastName = lastName;
}
 */



/*

 // Destructor
 ~User( );
 
 // getId
 // Returns the user ID
 int getID( ) const;
 
 // getLastName
 // Return the last name of the user
 
 // getFirstName
 // Return the first name
 
 // getHistory
 // Returns user's transaction history
 //History* getHistory() const; TODO
 
 // setLastName
 // Changes the user's last name
 
 // setFirstName
 // Changes the user's first name
 
 // operator<
 // Overload < operator
 bool operator<(const User&) const;
 
 private:
 // a unique identifier
 int userId;
 
 // the patron's last name
 string lastName;
 
 // the patron's first name
 string firstName;
 
 // the patron's transaction history
 //History history; TODO
 };

*/