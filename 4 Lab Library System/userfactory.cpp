//-----------------------------------------------------------------------------
// User Factory class: a factory that produces instances of users
// Includes the following features:
//  -- Creates users of a specified type
//-----------------------------------------------------------------------------

#include "userfactory.h"

// Sets the default values for the static class information
bool UserFactory::instanceFlag = false;
UserFactory* UserFactory::_instance = NULL;

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: The constructor is declared private to prevent clients from
    instantiating extra copies of the singleton.
 ----------------------------------------------------------------------------*/
UserFactory::UserFactory() {}

/*---------------------------------------------------------------------------
 ===== Instance
 Descripton: This is the "constructor" for the singleton. If an instance
    doesn't exist, it is created and returned. If it already does exist,
    it is returned.
 ----------------------------------------------------------------------------*/
UserFactory* UserFactory::instance() {
    if(!instanceFlag) {
        instanceFlag = true;
        _instance = new UserFactory;
    }
    return _instance;
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Destructor for factory. delete must be called upon the original
 instance call in order to correctly destroy all instances.
 ----------------------------------------------------------------------------*/
UserFactory::~UserFactory() {
    if(instanceFlag) {
        instanceFlag = false;
        _instance = NULL;
    }
}

/*---------------------------------------------------------------------------
 ===== Create User
 Descripton: Creates a user by reading data from the input file.
 ----------------------------------------------------------------------------*/
User* UserFactory::createUser(istream& input) {
    int id;
    string name;//, firstName, lastName;
    
    if(input.eof()) return NULL; // insufficient data
    input >> id; // get the id.
    input.get(); //throw away the space.
    if(input.eof()) return NULL; //insufficient data
    getline(input, name); // read the rest of the line, which is the name.
    
    User* u = new User(id, name); // create the user and return.
    return u;
}
