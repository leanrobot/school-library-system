//-----------------------------------------------------------------------------
// USERFACTORY.H
// UserFactory Class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// User Factory class: a factory that produces instances of users
// Includes the following features:
//  -- Creates users of a specified type
//-----------------------------------------------------------------------------

#ifndef USER_FACTORY_H
#define USER_FACTORY_H

#include <iostream>
#include <fstream>
#include "user.h"

class UserFactory {

public:
    // Singleton controlled creation function
    static UserFactory* instance();
    
    // CreateUser
    User* createUser(istream& infile);
    
    // Destructor
    ~UserFactory();

private:
    static bool instanceFlag;
    static UserFactory* _instance;
    
    UserFactory(); // private to prevent singleton creation.
    //d eclared, but not implemented, to prevent singleton cloning.
    UserFactory(UserFactory const& );
    void operator= (UserFactory const&);
    
};

#endif /* USERFACTORY_H */

