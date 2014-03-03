

//-----------------------------------------------------------------------------
// class Command
//
// Represents a base command that will be executed on a library. Other commands
// can be added by creating sub classes of this class with the command factory.
//
//-----------------------------------------------------------------------------

#include "prototype.h"
#include "hashable.h"
#include "library.h"

class Command : Prototype : Hashable {
public:
	virtual bool execute(Library l) = 0; // Virtual execute.
					// Implementations will use this to work
					// with the library.
    virtual void print() = 0; // Virtual print. each implementation
    				// will define it's print function.
};