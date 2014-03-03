

//-----------------------------------------------------------------------------
// class RemoveRecord
//
// Represents a command to be executed on a library.
//
// Assumptions:
//  -- user id will be set as something unique
//-----------------------------------------------------------------------------

#ifndef REMOVERECORD_H
#define REMOVERECORD_H
#include "command.h"

class RemoveRecord: public Command {
public:
	RemoveRecord(string title);
	~RemoveRecord();
	bool void execute(Library l); // implementation of
			// command execute. Removes a record from the
			// library system.

	Item* getItem(); // accessor
	void setItem(Item* i); // mutator
private:
	Item i; // the item that will be removed
		// from the library.
};

#endif