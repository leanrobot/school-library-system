
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

#ifndef USER_H
#define USER_H
#include <string>
#include "history.h"

using namespace std;
class User {
public:
    // Constructor
    User(int id, string name);
    //User( int id, string firstName, string lastName);
    
    // Destructor
    ~User( );
    
    // getId
    // Returns the user ID
    int getID( ) const;
    
    // getName
    // Return the name
    string getName() const;
    
    // getHistory
    // Returns user's transaction history
    History* getHistory();
    
    // setName
    // Changes the user's name
    void setName(string);
    
    // operator<
    // Overload < operator
    //bool operator<(const User&) const; 
  
private:
    // a unique identifier
    int userId;          
    
    // the patron's last name
    //string lastName;
    
    // the patron's first name
    string name;
    
    // the patron's transaction history
    History* userHistory;
};

#endif
