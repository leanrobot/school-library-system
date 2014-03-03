

//-----------------------------------------------------------------------------
// class History
//
// Command that displays the history of commands executed by a user.
//
//-----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H
#include "command.h"

class History: public Command {
public:
	History();	// Constructor
	~History();	// Destructor
    vector<Command*> getHistory(); //Retrieve the history list
private:
	Command[] cmds; // internal state of commands executed for user.
};

#endif