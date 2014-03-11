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

#include <fstream>
#include "transaction.h"
#include "hashtable.h"
#include "checkouttransaction.h"
#include "displaytransaction.h"
#include "returntransaction.h"
#include "historytransaction.h"

using namespace std;

// size of the array
const int FACTORY_MAX_SIZE = 26;

class TransactionFactory {
    
public:
    
    // Create the instance of transaction 
    static TransactionFactory* instance();
    
    //Destructor
    ~TransactionFactory( );
    Transaction* createTransaction(istream&);
                        // creates a Transaction of the desired type
  
private:
    TransactionFactory( );         // constructor
    
    // Variables associated with the singleton pattern.
    static bool instanceFlag;               // true if instance exists
    static TransactionFactory* _instance;   // pointer to singleton instance.
    
    // Declared, but not implemented, to prevent singleton cloning.
    TransactionFactory(TransactionFactory const&);
    void operator=(TransactionFactory const&);
    
    HashTable transactions;
};

#endif /* TRANSACTION_FACTORY_H */
