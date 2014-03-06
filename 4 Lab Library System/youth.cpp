#include "youth.h"

Youth:: Youth(){
    itemType = 'Y';
}

Youth:: Youth(string title,  string author, int year): Book ('Y', title, author, year){
}

//overloaded comparison operators
bool Youth:: operator<(const Item& item) const{
    const Youth& otherYouth = static_cast<const Youth&>(item);
    
//    if (otherYouth == NULL){
//        return false;
//    }
    
    if (this->title.compare(otherYouth.title)<0){
        return true;
    }
    
    if (this->title.compare(otherYouth.title)==0){
        if (this->author.compare(otherYouth.author) < 0){
            return true;
        }
    }
    return false;
}


bool Youth:: operator>(const Item& item) const{
    return !(*this < item) && *this != item;
}

bool Youth:: operator== (const Item& item)const{
    const Youth& otherYouth = static_cast<const Youth&>(item);
    
    return ((this->title.compare(otherYouth.title) == 0) &&
            (this->author.compare(otherYouth.author) == 0));
}

bool Youth:: operator!= (const Item& item)const{
    return !(*this == item);
}

//create an item
Item* Youth:: create(istream& infile){
    string author, title;
    
    getline(infile, author, ',');     // input author, looks for comma terminator
    
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
    
    int year;
    infile >> year;                     // input year
    
    //discard new line character.
    infile.get();
    
    Item* newYouthBook = new Youth (title, author, year);
    
    return newYouthBook;
}

void Youth:: print ()const{
    cout<< itemType<< ", "<< author<< ", "<< title<< endl;
}
