#include "history.h"

// constructor
History:: History( ){
    
}

// destructor
History:: ~History( ){
    
}

// add a new item
void History:: add( Transaction* oneTransaction){
       data.push_back(oneTransaction);
}

// display the transaction history
void History:: display( ) const{
    
    for (std::list<Transaction*>::const_iterator it = data.begin(); it != data.end(); it++){
        (*it)->print();
    }
    
}