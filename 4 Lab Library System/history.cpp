#include "history.h"
#include <list>

// constructor
History:: History( ){
    
}

// destructor
History:: ~History( ){
    for ( list<Transaction*>:: iterator it = data.begin(); it != data.end(); it++){
        delete (*it);
    }
}

// add a new item
void History:: add( Transaction* oneTransaction){
    data.push_back(oneTransaction);
}

list<Transaction*>& History::getHistory() {
    return data;
}
