#include "transactionfactory.h"

#include "checkouttransaction.h"
#include "displayTransaction.h"
#include "returntransaction.h"

TransactionFactory* TransactionFactory::instance() {
    static TransactionFactory transFact;
    
    return &transFact;
}
TransactionFactory::TransactionFactory() {
    Hashable* checkoutTrans = new CheckOutTransaction;
    Hashable* returnTrans = new ReturnTransaction;
    Hashable* displayLibrary = new DisplayTransaction;
    
    transactions.add(checkoutTrans->hash(), checkoutTrans);
    transactions.add(returnTrans->hash(), returnTrans);
    transactions.add(displayLibrary->hash(), displayLibrary);
    
}
TransactionFactory::~TransactionFactory() {
    //TODO
}

Transaction* TransactionFactory::createTransaction(istream& infile) {
    char itemType = infile.get(); //get the item type.
    infile.get(); //throwaway the space.
    
    //cout << "looking for " << itemType << endl;
    
    //read the first character
    if(transactions.contains(itemType)) {
        //cout << "found!\n";
        Hashable* hashed = transactions.get(itemType);
        //downcast to item class
        Transaction* trans = static_cast<Transaction*>(hashed);
        return trans->create(infile);
    }
    else {
        // read the rest of the line
        string throwAway;
        getline(infile, throwAway);
    }
    return NULL;
}