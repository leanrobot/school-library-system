
//-----------------------------------------------------------------------------
// class CommandFactory
//
// Will be used to build additional commands inside this factory.
//
//-----------------------------------------------------------------------------

#include "command.h"
#include <map>

class CommandFactory {
public:
	CommandFactory();	// Constructor
	~CommandFactory();	// Destructor
	Command* createCommand(string rawData);
						// Returns an implementation
						// of the Command class based on
						// rawData.
private:
	UserFactory userF; // The user factory
	ItemFactory itemF; // the item factory.
	map<int,Command*> commands; // available commands the factory creates.
};