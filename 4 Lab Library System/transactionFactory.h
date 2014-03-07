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
using namespace std;
const int FACTORY_MAX_SIZE = 26;

class TransactionFactory {
    
public:
    static TransactionFactory* instance();
    ~TransactionFactory( );        // destructor
    Transaction* createTransaction(istream&); // creates a Transaction of the desired type
  
private:
    TransactionFactory( );         // constructor
    
    // Declared, but not implemented, to prevent singleton cloning.
    TransactionFactory(TransactionFactory const&);
    void operator=(TransactionFactory const&);
};

#endif
