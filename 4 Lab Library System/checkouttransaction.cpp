#include "checkouttransaction.h"


Transaction* CheckOutTransaction:: create(istream&infile){
    
    infile >> userId;
    infile.get(); // read the blank space
    
    
}

void CheckOutTransaction:: execute(ItemCollection& items, map <int, User*> & userCollection){
    
}