//-----------------------------------------------------------------------------
// MANAGER.CPP
// Manager class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Manager class: is a class which reads data from files and create users,
// items and transactions objects. The User objects are added to the
// UserCollection users and the items objects are added to the ItemCollection
// items. Transaction objects are created and the the function execute is
// called on them. The class implements following methods:
// -- buildUsers
// -- buildItems
// -- processTransaction
//
// Assumptions:
// -- three data files will be provided, one contains information of users, one
//    contains information about items, and one contains transactions that
//    users performed.
// -- the data in each file is in the correct format.
// -- if the data contain incorrect values (e.g. wrong type of book),
//    the object will not be created and therefore added/executed.
//-----------------------------------------------------------------------------
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
    // retrive the users (map) and delete all users from the map
    for (std::map<int,User*>::iterator it=userCollection.begin();
         it!=userCollection.end(); ++it)
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
    
    // read the file until there is no data left
    while(!input.eof()) {
        // creat user object
        User* user = userFactory->createUser(input);
        
        // check if the user is not a NULL
        if(user != NULL) {
            // check if the user with given Id doe not already exist in
            // the userCollection and if exists print information about it
            if (userCollection.count(user->getID())>0){
                cout<< "Patron with ID "<< user->getID()<< " already exists."
                <<endl;
            }
            // otherwise, add user to userCollection
            userCollection[user->getID()] = user;
        }
    }
   // cout << userCollection.size() << " users added\n";
}

/*-----------------------------------------------------------------------------
 ===== Build Items
 Descripton: Builds the itemCollection. The input file is read until there is
 no data left. It is passed to the itemfactory, which constructs the right type 
 of item.
 Pre:
 Post:file is read, and all correct items are created
 -----------------------------------------------------------------------------*/
void Manager::buildItems(istream& input) {
   
    // read the file until there is no data left
    while(!input.eof()) {
        // creat the right type of item
        Item* item = itemFactory->createItem(input);
        
        // if the item is not a NULL
        if(item != NULL) {
            // initialized the item
            item->initialize(input);
            // add the item to itemCollection
            itemCollection.insert(item);
        }
    }
}

/*-----------------------------------------------------------------------------
 ===== Process Transaction
 Descripton: Read the commands from the command file and processes as the file
 is traversed.
 Pre:
 Post: file is read, and all correct commands are executed.
 -----------------------------------------------------------------------------*/
void Manager::processTransaction(istream& infile) {
    
    // read the file until there is no data left
    while(!infile.eof()) {
        
        // create the right type of transaction
        Transaction* trans = transactionFactory->createTransaction(infile);
        
        if(trans != NULL) {
            // execute the transaction
            trans->execute(itemCollection, userCollection);
            // delete the transaction
            delete trans;
        }
    }
}


