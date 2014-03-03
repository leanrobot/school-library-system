

//-----------------------------------------------------------------------------
// class DisplayLibrary
//
// Command will be used to display the entire contents of the library
// in sorted order.
//
//-----------------------------------------------------------------------------

#ifndef DISPLAYLIBRARY_H
#define DISPLAYLIBRARY_H
#include "command.h"

class DisplayLibrary: public Command {
public:
	DisplayLibrary();	// Constructor
	~DisplayLibrary();	// Destructor
	bool void execute(Library l);	// Implementation of
				// execute. Displays the library contents
};

#endif