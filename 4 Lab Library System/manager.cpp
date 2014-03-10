#include "manager.h"
#include "userfactory.h"
#include "itemfactory.h"

#include "displaytransaction.h"
#include "checkouttransaction.h"

/*-----------------------------------------------------------------------------
 ===== Constructor
 Descripton: Retrieves singleton instances of all the factories.
 Pre:
 Post: manager is initialized.
 -----------------------------------------------------------------------------*/
Manager::Manager() {
    //user map is static constructed.
    userFactory = UserFactory::instance();
    itemFactory = ItemFactory::instance();
    transactionFactory = TransactionFactory::instance();
    
}
/*-----------------------------------------------------------------------------
 ===== Destructor
 Descripton: destroys singletons and deletes users.
 Pre:
 Post: deallocated.
 -----------------------------------------------------------------------------*/
Manager::~Manager() {
    for (std::map<int,User*>::iterator it=users.begin(); it!=users.end(); ++it)
        delete it->second;
    
    delete userFactory;
    delete itemFactory;
    delete transactionFactory;
}
/*-----------------------------------------------------------------------------
 ===== Build Users
 Descripton: Builds the user collection. The input file is read until there is
    no data left. It is passed to the userfactory, who constructs the user.
 Pre
 Post: users are initialized from file. File is ready completely.
 -----------------------------------------------------------------------------*/
void Manager::buildUsers(istream& input) {
    while(!input.eof()) {
        User* user = userFactory->createUser(input);
        
        if(user != NULL) {
            users[user->getID()] = user;
        }
    }
    cout << users.size() << " users added\n";
    
}
/*-----------------------------------------------------------------------------
 ===== Build Items
 Descripton: Builds the item trees from the input file. The file is read 
 until it is empty.
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
void Manager::buildItems(istream& input) {
    while(!input.eof()) {
        Item* item = itemFactory->createItem(input);
        
        // if the item factory creates an item, add it to the item collection.
        if(item != NULL) {
            item->initialize(input);
            
            items.insert(item);
        }
    }
}
/*-----------------------------------------------------------------------------
 ===== Process Transaction
 Descripton: This read from the command file and processes as the file is 
    traversed.
 Pre:
 Post: file is read, and all commands are executed.
 -----------------------------------------------------------------------------*/
void Manager::processTransaction(istream& infile) {
    while(!infile.eof()) {
        Transaction* trans = transactionFactory->createTransaction(infile);
        
        if(trans != NULL) {
            trans->execute(items, users);
            delete trans;
        }
    }
}


