//-----------------------------------------------------------------------------
// TRANSACTION.CPP
// Transaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Transaction class: is a an abstract class which is a unified interface of
// all of the Transaction available within program. Includes the following
// features:
// -- create a Transaction object
// -- execute certain actions of a Transaction
// -- hashing function which return type of the transaction
// -- print method to display information about the transaction
//-----------------------------------------------------------------------------

#include "transaction.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Transaction class.
----------------------------------------------------------------------------*/
Transaction:: Transaction(){
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Destructor
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
