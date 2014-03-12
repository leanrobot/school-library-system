//-----------------------------------------------------------------------------
// History.CPP
// History class
// Authors: Magdalena Grzmiel and Thomas Petit
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

#include "history.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Doesn't need to do anything
  ----------------------------------------------------------------------------*/
History:: History( ) {}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Iterates through the history list of transactions and deletes
 each transaction.
 Post: all history attributes are deallocated.
 ----------------------------------------------------------------------------*/
History:: ~History( ){
    list<Transaction*>:: iterator it = data.begin();
    for (; it != data.end(); it++){
        delete (*it);
    }
}

/*---------------------------------------------------------------------------
 ===== Add
 Descripton: Adds a Transaction to the command history. The new commands is 
 added to the end of the list, so the order is from oldest -> newest.
 ----------------------------------------------------------------------------*/
void History:: add( Transaction* oneTransaction){
    data.push_back(oneTransaction);
}

/*---------------------------------------------------------------------------
 ===== Get History
 Descripton: Returns the list which contains history of commands from
 oldest -> newest.
 ----------------------------------------------------------------------------*/
list<Transaction*>& History::getHistory() {
    return data;
}
