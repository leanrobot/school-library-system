
//-----------------------------------------------------------------------------
// History class: Represents the history of a patron's transactions. Includes
// the following features:
//  -- Add a new HistoryEntry item to the list
//  -- Display all transaction history for the user
// Assumptions:
//  -- Assumes deleting items from the history will not be necessary
//  -- if an item is mistakenly checked out or returned, performing the
//     opposite function should serve to "undo" the action
//  -- Assumes there is not a need to paginate the history
//  -- Assumes there is not a need to display partial history
//-----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include <list>
#include <iostream>


using namespace std;
class Transaction; // forward reference
class History {
    
public:
    
	// constructor
    History( );
    
    // destructor
    ~History( );
    
    // add a new item
    void add(Transaction* );
    
    // display the transaction history
    void display( ) const;
    
    list<Transaction*>& getHistory();
    
private:
    
    // list of transaction history items
    list <Transaction*> data;
    
};

#endif
