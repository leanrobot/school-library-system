#include "fiction.h"

    
Fiction:: Fiction(): Book(){
    itemType = 'F';
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
    char itemType = infile.get(); // read item type
    infile.get();                  // read and igonore blanke space
    infile.get(); // read and ignore itemformat
    infile.get(); // read blank space
    
    string author, title;
    
    getline(infile, author, ',');     // input author, looks for comma terminator
    
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
    
    //Item* newFictionBook = new Fiction(title, author, year);
    //return newFictionBook;
    
    this->setItemType(itemType);
    this->setAuthor(author);
    this -> setTitle(title);
}


void Fiction:: print()const {
    cout<< itemType<< ", " << author<< ", "<<title<< ", "<< year<<endl;
}
