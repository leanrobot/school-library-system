#include "transaction.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Transaction class.
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
Transaction:: Transaction(){
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Destructor
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
Transaction:: ~Transaction(){
    
}

/*---------------------------------------------------------------------------
 ===== hash
 Descripton: Hash function
 Pre:
 Post: Returns transaction type
 ----------------------------------------------------------------------------*/
char Transaction:: hash() const{
    return transactionType;
}
