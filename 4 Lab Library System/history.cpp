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
