//-----------------------------------------------------------------------------
// User Factory class: a factory that produces instances of users
// Includes the following features:
//  -- Creates users of a specified type
//-----------------------------------------------------------------------------

#ifndef ____Lab_Library_System__userfactory__
#define ____Lab_Library_System__userfactory__

#include <iostream>
#include <fstream>

#include "user.h"

class UserFactory {
public:
    static UserFactory* instance(); // Singleton controlled creation function
    User* createUser(istream&);
    ~UserFactory();
private:
    static bool instanceFlag;
    static UserFactory* _instance;
    
    UserFactory(); // private to prevent singleton creation.
    //declared, but not implemented, to prevent singleton cloning.
    UserFactory(UserFactory const&);
    void operator=(UserFactory const&);
    
};

#endif /* defined(____Lab_Library_System__userfactory__) */
