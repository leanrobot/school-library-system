

//-----------------------------------------------------------------------------
// class ReturnItem
//
// Represents a command to be executed on a library. This command will mark
// an item as returned in the library.
//
//-----------------------------------------------------------------------------

#ifndef RETURNITEM_H
#define RETURNITEM_H
#include "command.h"

class ReturnItem: public Command {
public:
	ReturnItem(); // Constructor
	~ReturnItem(); // Destructor
	bool void execute(Library l); // implementation of
				// Command execute. Returns an item from a user
				// to the library system.

	Item* getItem(); // accessor
	void setItem(Item* i); //mutators
private:
	Item i; // the item to return.
};

#endif