#include "manager.h"
#include "userfactory.h"

Manager::Manager() {
    //user map is static constructed.
}
Manager::~Manager() {
    //TODO write this
}

void Manager::buildUsers(istream& input) {
    UserFactory userFact;
    
    while(!input.eof()) {
        User* user = userFact.createUser(input);
        
        if(user != NULL) {
            users[user->getID()] = user;
        }
    }
    cout << users.size() << " users added";
    
}