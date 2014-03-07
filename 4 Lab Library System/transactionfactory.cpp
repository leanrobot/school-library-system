#include "transactionfactory.h"

TransactionFactory* TransactionFactory::instance() {
    static TransactionFactory transFact;
    
    return &transFact;
}
TransactionFactory::TransactionFactory() {
    //TODO
}
TransactionFactory::~TransactionFactory() {
    //TODO
}

Transaction* createTransaction(istream& infile) {
    return NULL; //TODO
}