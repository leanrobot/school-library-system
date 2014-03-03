

//-----------------------------------------------------------------------------
// class User
//
// Represents a patron that is visiting the library and performing some
// commands. They are represented by a name and a unique identification
// number. They also contain a history of all commands related to them.
//
// Assumptions:
//  -- user id will be set as something unique
//-----------------------------------------------------------------------------

#ifndef USER_H
#define USER_H
#include "history.h"
using namespace std;

class User {
public:
	User(); // Constructor
	~User(); // Destructor
	History getHistory(); // accessor
	string getName(); //accessor 
	int getId(); //accessor

	void setHistory(History h); // mutator
	void setName(string n); // mutator
	void setId(int i); // mutator
private:
	string name; // user's name
	int id; // user id
	History history; // user's history
};

#endif