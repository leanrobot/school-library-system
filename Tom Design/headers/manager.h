#ifndef MANAGER_H
#define MANAGER_H
#include <queue>
#include "userfactory.h"
#include "commandfactory.h"
#include "itemfactory.h"
#include "library.h"

class Manager {
public:
	Manager(); // Constructor
	~Manager(); // Destructor
    void run(); // Runs the applications
private:
    UserFactory u; // Factory for users.
    CommandFactory cf; // Factory for commands.
    ItemFactory i; // Factory for items.
    Library l; // Library object
    queue<Command> q; // Queue of commands to execute.

    ifstream userFile; // file holding raw user data.
    ifstream commandFile; // file holding raw command data.
    ifstream itemFile; // file containing raw item data.
};

#endif