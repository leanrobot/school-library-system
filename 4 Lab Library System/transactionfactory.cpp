//-----------------------------------------------------------------------------
// Transaction Factory class: a factory that produces instances of transactions
// Includes the following features:
//  -- Creates transactions of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 transactions types are present
//-----------------------------------------------------------------------------

#include "transactionfactory.h"

// Default values for static class variables for singleton.
bool TransactionFactory::instanceFlag = false;
TransactionFactory* TransactionFactory::_instance = NULL;

/*---------------------------------------------------------------------------
 ===== Instance creation
 Descripton: This is the "constructor" for the singleton. If an instance
    doesn't exist, it is created and returned. If it already does exist,
    it is returned.
 ----------------------------------------------------------------------------*/
TransactionFactory* TransactionFactory::instance() {
    if(!instanceFlag) {
        TransactionFactory::instanceFlag = true;
        TransactionFactory::_instance = new TransactionFactory;
    }
    return _instance;
}
/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for the item factory. The different types of supported
    items are hardcoded here. They are added manually to the hashtable.
 ----------------------------------------------------------------------------*/
TransactionFactory::TransactionFactory() {
    Hashable* checkoutTrans = new CheckOutTransaction;
    Hashable* returnTrans = new ReturnTransaction;
    Hashable* displayLibrary = new DisplayTransaction;
    Hashable* historyTrans = new HistoryTransaction;
    
    transactions.add(checkoutTrans->hash(), checkoutTrans);
    transactions.add(returnTrans->hash(), returnTrans);
    transactions.add(displayLibrary->hash(), displayLibrary);
    transactions.add(historyTrans->hash(), historyTrans);
    
}
/*---------------------------------------------------------------------------
 ===== Destructor
    Descripton: Destructor for factory. delete must be called upon the original
    instance call in order to correctly destroy all instances.
 ----------------------------------------------------------------------------*/
TransactionFactory::~TransactionFactory() {
    if(instanceFlag) {
        instanceFlag = false;
        _instance = NULL;
    }
}

/*---------------------------------------------------------------------------
 ===== Create Transaction
 Descripton: Reads from the input stream to determine the type of transaction
    to create. The first character is read, and this is used to retrieve the
    correct type from the hash table.
 ----------------------------------------------------------------------------*/
Transaction* TransactionFactory::createTransaction(istream& infile) {
    char itemType = infile.get(); //get the item type.
    infile.get(); //throwaway the space.
        
    //read the first character
    if(transactions.contains(itemType)) {
        Hashable* hashed = transactions.get(itemType);
        //downcast to item class
        Transaction* trans = static_cast<Transaction*>(hashed);
        return trans->create(infile);
    }
    else { // not supported transaction
        // read the rest of the line and discard
        string throwAway;
        getline(infile, throwAway);
    }
    return NULL;
}