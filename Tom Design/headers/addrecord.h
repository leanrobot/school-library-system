
//-----------------------------------------------------------------------------
// class AddRecord
//
// Represents a command that will be executed on the library to add
// as record of an item.
//
//-----------------------------------------------------------------------------

#ifndef COMMAND_H
#define COMMAND_H
#include "command.h"

class AddRecord : public Command {
public:
	AddRecord(); 	// Constructor
	~AddRecord(); 	// Destructor
	bool void execute(Library l); // Implementation of Command execute
						// Adds a record to the library system passed.
private:
	Item i; // The item to be added when execute is called.
};

#endif