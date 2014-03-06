#include "fiction.h"

    
Fiction:: Fiction(): Book(){
    itemType = 'F';
}

Fiction:: Fiction(string title,  string author, int year): Book ('F', title, author, year){
}

	
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

bool Fiction:: operator== (const Item& item) const{
    const Fiction& otherFiction = static_cast<const Fiction&>(item);
    
    return (/*otherFiction != NULL && */ (this->author.compare(otherFiction.author)== 0) && (this->title.compare(otherFiction.title) == 0) && this->year == otherFiction.year);
}
	
    //create an item
Item* Fiction:: create(istream& infile){
           
    string author, title;
    
    getline(infile, author, ',');     // input author, looks for comma terminator
            
    infile.get();                     // get (and ignore) blank before title
    getline(infile, title, ',');      // input title
            
    int year;
    infile >> year;                     // input year
    
    //discard new line character
    infile.get();
    
    Item* newFictionBook = new Fiction(title, author, year);
    
    return newFictionBook;

}
void Fiction:: print()const {
    cout<< itemType<< ", " << author<< ", "<<title<< ", "<< year<<endl;
}
