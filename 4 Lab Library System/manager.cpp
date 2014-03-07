#include "manager.h"
#include "userfactory.h"
#include "itemfactory.h"

Manager::Manager() {
    //user map is static constructed.
    for(int i=0; i < MAX_ITEM_TYPES; i++) {
        items[i] = NULL;
    }
}
Manager::~Manager() {
    for (int i = 0; i < MAX_ITEM_TYPES; i++){
        if (items[i]!=NULL){
        delete items[i];
        }
    }
    
    for (std::map<int,User*>::iterator it=users.begin(); it!=users.end(); ++it)
        delete it->second;

    users.clear();
    
    
}

void Manager::buildUsers(istream& input) {
    //UserFactory userFact;
    
    while(!input.eof()) {
        User* user = userFactory.createUser(input);
        
        if(user != NULL) {
            users[user->getID()] = user;
        }
    }
    cout << users.size() << " users added";
    
}

void Manager::buildItems(istream& input) {
    while(!input.eof()) {
        Item* item = itemFactory.createItem(input);
        item->initialize(input);
        
        if(item != NULL) {
            char itemType = item->hash();
            int index = itemType - 'A';
            if(items[index] == NULL) {
                items[index] = new ItemCollection;
            }
            items[index]->insert(item);
        }
    }
    
    cout << endl;
    for(int i=0; i<MAX_ITEM_TYPES; i++) {
        ItemCollection* ic = items[i];
        
        if (ic != NULL){
         cout << "COLLECTION FOR " << char('A'+i) << endl;
            ic->print();
        }
    }
    
        //if(ic != NULL) {
         //   cout << "COLLECTION FOR " << char('A'+i) << endl;
//            for(int j=0; j<ic->size(); j++) {
//                ic->retrieve(j)->print();
//            }
  //      }

//    }
}


