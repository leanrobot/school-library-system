
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

class User {
public:
    // Constructor
    User( int, string, string);
    
    // Destructor
    ~User( );
    
    // getId
    // Returns the user ID
    int getID( ) const;
    
    // getLastName
    // Return the last name of the user
    string getLastName() const;
    
    // getFirstName
    // Return the first name
    string getFirstName() const;
    
    // getHistory
    // Returns user's transaction history
    History* getHistory() const;
 
    // setLastName
    // Changes the user's last name
    void setLastName(string);
    
    // setFirstName
    // Changes the user's first name
    void setFirstName(string);
    
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
    History history;       
};

#endif
