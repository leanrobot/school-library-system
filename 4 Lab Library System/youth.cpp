#include "youth.h"

Youth:: Youth(){
}

Youth:: Youth(string title,  string author, int year): Book ('Y', title, author, year){
}

//overloaded comparison operators
bool Youth:: operator<(const Item& item) const{
    const Youth* otherYouth = static_cast<const Youth*>(&item);
    
    if (otherYouth == NULL){
        return false;
    }
    
    if (this->title < otherYouth->title){
        return true;
    }
    
    if (this->title == otherYouth->title){
        if (this->author < otherYouth->author){
            return true;
        }
    }
    return false;
}

bool Youth:: operator== (const Item& item)const{
    const Youth* otherYouth = static_cast<const Youth*>(&item);
    return (otherYouth != NULL && this->title == otherYouth->title && this->author == otherYouth->author
            && this->year == otherYouth->year);
}

//create an item
Item* Youth:: create(istream& infile){
    string author, title;
    
    infile.get();                     // get (and ignore) blank before author
    getline(infile, author, ',');     // input author, looks for comma terminator
    
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
    
    int year;
    infile >> year;                     // input year
    
    Item* newYouthBook = new Youth (title, author, year);
    
    return newYouthBook;
}

void Youth:: print ()const{
    cout<< itemType<< ", "<< author<< ", "<< title<< endl;
}
