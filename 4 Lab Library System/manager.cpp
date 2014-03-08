#include "manager.h"
#include "userfactory.h"
#include "itemfactory.h"

#include "displaytransaction.h"
#include "checkouttransaction.h"

Manager::Manager() {
    //user map is static constructed.
    userFactory = UserFactory::instance();
    itemFactory = ItemFactory::instance();
    transactionFactory = TransactionFactory::instance();
    
}
Manager::~Manager() {
    //for (std::map<int,User*>::iterator it=users.begin(); it!=users.end(); ++it)
      //  delete it->second;
    delete userFactory;
    delete itemFactory;
    delete transactionFactory;
}

void Manager::buildUsers(istream& input) {
    //UserFactory userFact;
    
    while(!input.eof()) {
        User* user = userFactory->createUser(input);
        
        if(user != NULL) {
            users[user->getID()] = user;
        }
    }
    cout << users.size() << " users added\n";
    
}

void Manager::buildItems(istream& input) {
    while(!input.eof()) {
        Item* item = itemFactory->createItem(input);
        
        if(item != NULL) {
            item->initialize(input);
            
            items.insert(item);
        }
    }
    
    /*
    cout << endl;
    int size;
    ItemTree** its = items.retrieveAll(size);
    for(int i=0; i<size; i++) {
        ItemTree* ic = its[i];
        
        if (ic != NULL){
         cout << "COLLECTION FOR " << char('A'+i) << endl;
            ic->print();
        }
    }
     */
    
        //if(ic != NULL) {
         //   cout << "COLLECTION FOR " << char('A'+i) << endl;
//            for(int j=0; j<ic->size(); j++) {
//                ic->retrieve(j)->print();
//            }
  //      }

//    }
}

void Manager::processTransaction(istream& infile) {
    while(!infile.eof()) {
        Transaction* trans = transactionFactory->createTransaction(infile);
        
        if(trans != NULL) {
            trans->execute(items, users);
            delete trans;
        }
    }
}

void Manager::testTransactions() {
    Transaction* t = new DisplayTransaction;
    t->execute( this->items, this->users);
    
    t = new CheckOutTransaction;
}


