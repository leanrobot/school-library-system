#include "transaction.h"


Transaction:: Transaction(){
}


Transaction:: ~Transaction(){
    
}
 
char Transaction:: hash() const{
    return transactionType;
}
