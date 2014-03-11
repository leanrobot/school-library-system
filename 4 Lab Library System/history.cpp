#include "history.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Doesn't need to do anything
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
History:: History( ) {}

// destructor
History:: ~History( ){
    for ( list<Transaction*>:: iterator it = data.begin(); it != data.end(); it++){
        delete (*it);
    }
}

/*---------------------------------------------------------------------------
 ===== Add
 Descripton: Adds a Transaction to the command history. The new commands is added to
    the end of the list, so the order is from oldest -> newest.
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
void History:: add( Transaction* oneTransaction){
    data.push_back(oneTransaction);
}

/*---------------------------------------------------------------------------
 ===== Get History
 Descripton: Returns the list which contains history of commands from
    oldest -> newest.
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
list<Transaction*>& History::getHistory() {
    return data;
}
