#include "periodical.h"


Periodical:: Periodical(){
    itemType = 'P';
}

Periodical:: Periodical(string title, int month, int year): Item('P', title, year){
    this->month = month;
}

int Periodical:: getMonth() const{
    return this->month;
}

void Periodical:: setMonth(int newMonth){
    this->month = newMonth;
}


bool Periodical::operator<(const Item& item) const {
    
	const Periodical& otherPeriodical = static_cast<const Periodical&>(item);
    
//	if (otherPeriodical == NULL) {
//		return false;
//	}
    
	if (this->year < otherPeriodical.year) {
		return true;
	}
    
	if (this->year == otherPeriodical.year) {
		if (this->month < otherPeriodical.month) {
			return true;
		} else if (this->month == otherPeriodical.month) {
			if (this->title.compare(otherPeriodical.title)<0)
				return true;
		} else {
			return false;
		}
	}
    return false;
}

bool Periodical::operator>(const Item& item) const {
    return !(*this < item) && *this != item;
}


bool Periodical:: operator== (const Item& item) const{
    const Periodical& otherPeriodical = static_cast <const Periodical&> (item);

    return (/*otherPeriodical != NULL && */(this -> title.compare(otherPeriodical.title)==0)
            && this->month == otherPeriodical.month && this->year == otherPeriodical.year);
}

bool Periodical:: operator!= (const Item& item) const{
    return !(*this == item);
}

Item* Periodical:: create(istream& infile){
    string title;
    
    getline(infile, title, ',');
    
    int month, year;
    infile >> month;
    infile >> year;
    
    Item* newPeriodical = new Periodical (title, month, year);
    
    //discard new line character
    infile.get();
    
    return newPeriodical;

}

void Periodical:: print ()const{
    cout<< itemType<< ", " << title<< ", "<< month<< ", "<< year<<endl;
}

