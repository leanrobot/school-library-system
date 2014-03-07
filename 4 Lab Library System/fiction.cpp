#include "fiction.h"
#include <iomanip>
#include <iostream>

    
Fiction:: Fiction(): Book(){
    itemType = 'F';
    itemCategoryFriendlyName = "Fiction";
}

//Fiction:: Fiction(string title,  string author, int year): Book ('F', title, author, year){
//}

	
    //overloaded comparison operators
bool Fiction:: operator<(const Item& item) const{
    
    const Fiction& otherFiction = static_cast<const Fiction&>(item);
//        
//    if (otherFiction == NULL){
//        return false;
//    }
    
    if (this->author.compare(otherFiction.author) < 0){
        return true;
    }

    if (this->author.compare(otherFiction.author) == 0){
        if (this->title.compare(otherFiction.title)<0){
            return true;
        }
    }
    
    return false;
}

bool Fiction:: operator>(const Item& item) const{
    return !(*this < item) && *this != item;
}


bool Fiction:: operator== (const Item& item) const{
    const Fiction& otherFiction = static_cast<const Fiction&>(item);
    
    return ((this->author.compare(otherFiction.author)== 0) &&
            (this->title.compare(otherFiction.title) == 0));
}

bool Fiction:: operator!= (const Item& item) const{
    return !(*this==item);
}


Item* Fiction:: create(){
    return new Fiction();
}

   //create an item
void Fiction:: initialize(istream& infile){
    string author, title;
    
    getline(infile, author, ',');     // input author, looks for comma terminator
    
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
    
    int year;
    infile >> year;                     // input year
    
    //discard new line character
    infile.get();
    
   // Item* newFictionBook = new Fiction(title, author, year);
    this->setAuthor(author);
    this -> setTitle(title);
    this->setYear(year);
}

void Fiction:: initializePartial(istream& infile){
    infile.get(); // read and ignore itemformat
    infile.get(); // read blank space
    
    string author, title;
    
    getline(infile, author, ',');     // input author, looks for comma terminator
    
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
    
    //Item* newFictionBook = new Fiction(title, author, year);
    //return newFictionBook;
    
    this->setAuthor(author);
    this -> setTitle(title);
}


void Fiction:: print()const {
    cout <<
        " " << setw(AVAILABLE_COL_WIDTH) << (totalCopies - checkedOutCopies) <<
        " " << setw(AUTHOR_COL_WIDTH) << author.substr(0, AUTHOR_COL_WIDTH) <<
        " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) <<
        " " << setw(YEAR_COL_WIDTH) << year << endl;
}

void Fiction:: printHeader() const {
    cout << "Fiction:" << endl;
    cout <<
        setw(AVAILABLE_COL_WIDTH+2) << "AVAIL" <<
        setw(AUTHOR_COL_WIDTH+1) << "AUTHOR" <<
        setw(TITLE_COL_WIDTH+1) << "TITLE" <<
        setw(YEAR_COL_WIDTH+1) << "YEAR" << endl;
    
    
}
