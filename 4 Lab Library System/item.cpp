#include "item.h"

Item:: Item(){
    totalCopies = 5;
    checkedOutCopies = 0;
    itemFormat = 'H';
    cout.setf(ios::left, ios::adjustfield);
}

Item:: ~Item(){
}

Item:: Item (char type, string title, int year) {
    this->itemType = type;
    this ->year = year;
    this->title = title;
}


char Item:: getItemType() const{
    return itemType;
}

void Item:: setItemType(char type){
    itemType = type;
}

//set the total number of copies of item
void Item:: setTotalCopies(int newTotalCopies){
    totalCopies = newTotalCopies;
}

//retrieve the total copies of item
int Item:: getTotalCopies() const{
    return totalCopies;
}

//set the number of copies checked out
void Item:: setCheckedOutCopies (int newCheckOutCopies){
    checkedOutCopies = newCheckOutCopies;
}

//retrieve number of copies checked out
int Item:: getCheckedOutCopies() const{
    return checkedOutCopies;
}

//retrieve the publication date of the media
int Item:: getYear() const{
    return year;
}

//set the year with the int parameter
void Item:: setYear(int newYear){
    year = newYear;
}

//retrieve the title
string Item:: getTitle() const{
    return title;
}

//set the title to the string parameter
void Item:: setTitle(string newTitle){
    title = newTitle;
}


char Item:: hash()const{
    return itemType;
}

