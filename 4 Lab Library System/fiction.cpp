#include "fiction.h"
    
public:
	Fiction();
	
    //constructor with parameters for author, title, year
Fiction(string author , string, int){
    
}
	
    //overloaded comparison operators
virtual bool operator<(const Item&) const{
    
}
    
    virtual bool operator== (const Item&)const;
	
    //create an item
    virtual Item* create();
	
};