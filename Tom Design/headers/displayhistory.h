

//-----------------------------------------------------------------------------
// class DisplayHistory
//
// Sub class of Command that will display history of a specific user.
//
//-----------------------------------------------------------------------------

#ifndef DISPLAYHISTORY_H
#define DISPLAYHISTORY_H
#include "command.h"

class DisplayHistory: public Command {
public:
	DisplayHistory();	// Constructor.
	~DisplayHistory();	// Destructor.
	bool void execute(Library l); // Implementation of execute.
	void setUser(User u); // sets the private user entity.
private:
	User u;	// user to display history for.
};

#endif