

//-----------------------------------------------------------------------------
// class CheckoutItem
//
// A sub class of command that will check out an item from the library to a
// specific user.
//
//-----------------------------------------------------------------------------

#ifndef CHECKOUTITEM_H
#define CHECKOUTITEM_H
#include "command.h"

class CheckoutItem: public Command {
public:
	CheckoutItem();		// Constructor
	~CheckoutItem();	// Destructor
	bool void execute(Library l);	// implementation 
					// of Command execute. Checks out an 
					// item to a user.
private:
	Item i; // the item to be checked out
	User u; // the user to check out the item to.
};

#endif