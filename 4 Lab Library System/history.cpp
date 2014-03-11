#include "history.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Doesn't need to do anything
 Pre:
 Post:
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
