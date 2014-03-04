//-----------------------------------------------------------------------------
// Transaction Factory class: a factory that produces instances of transactions
// Includes the following features:
//  -- Creates transactions of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 transactions types are present
//-----------------------------------------------------------------------------
#ifndef TRANSACTION_FACTORY_H
#define TRANSACTION_FACTORY_H
#include <string>
#include "transaction.h"

const int FACTORY_MAX_SIZE = 26;

class TransactionFactory {
    
public:
    TransactionFactory( );         // constructor
    ~TransactionFactory( );        // destructor
    Transaction* createIt(string); // creates a Transaction of the desired type
  
private:
    
    //Storage for Transaction creation objects
    Transaction* transactionFactory[FACTORY_MAX_SIZE];

    //use hash function to get hash index
    int hash(char);
};

#endif
