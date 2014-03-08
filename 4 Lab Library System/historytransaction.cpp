#include "historytransaction.h"
#include "itemfactory.h"


HistoryTransaction:: HistoryTransaction (){
    transactionType = 'H';
    user=NULL;
}

HistoryTransaction:: ~HistoryTransaction (){
    delete user;
}



Transaction* HistoryTransaction:: create(istream&infile){
    HistoryTransaction * newTransaction = new HistoryTransaction;
    
    int userId;
    infile >>userId;
    newTransaction->userId = userId;
    infile.get(); // read the blank space
    ItemFactory* factory = ItemFactory::instance();
    //newTransaction->lookUpItem = factory -> createItem (infile);
    //newTransaction->lookUpItem->initializePartial(infile);
    
    return newTransaction;
}

void HistoryTransaction:: execute(ItemCollection& items, map <int, User*> & userCollection){
    
    
    if (userCollection.count(this->userId)>0) {      // check if the user with
        //the given id is in the map
        user = userCollection[this->userId]; // and if exist assign it to the oneUser
        
        list<Transaction*>& userHistory = user->getHistory()->getHistory();
        
        list<Transaction*>::iterator iter = userHistory.begin();
        cout<< "*** Patron ID = " << userId << " " <<user->getName() << endl;
        for(; iter!=userHistory.end(); iter++) {
            (*iter)->print();
        }
        
    }else {
        cout << "Command not executed: No copies available\n";
        print(); //TODO
    }
    
}

void HistoryTransaction:: print() const{
    cout << setw (COMMAND_COL_WIDTH) << "Checkout" ;
    // item->print();
}