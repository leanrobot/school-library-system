#include "periodical.h"
#include <iomanip>


Periodical:: Periodical(){
    itemType = 'P';
    itemCategoryFriendlyName = "Periodicals";
}

Periodical:: Periodical(string title, int month, int year)
: Item('P', title, year){
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

    return ((this -> title.compare(otherPeriodical.title)==0)
            && this->month == otherPeriodical.month
            && this->year == otherPeriodical.year);
}

bool Periodical:: operator!= (const Item& item) const{
    return !(*this == item);
}

Item* Periodical:: create(){
    Item* newPeriodical = new Periodical;
    return newPeriodical;

}

void Periodical::initialize(istream& infile) {
    string title;
    
    getline(infile, title, ',');
    
    int month, year;
    infile >> month;
    infile >> year;

    //discard new line character
    infile.get();
    
    this->setTitle(title);
    this->setMonth(month);
    this->setYear(year);
}
void Periodical::initializePartial(istream& infile) {
    string  title;
    int year, month;
    
    //discard the "Hardcopy" and extra space.
    infile.get(); infile.get();
    
    infile >> year;
    infile >> month;
    
    getline(infile, title, ',');
    
    //discard the newline
    infile.get();
    
    this->setTitle(title);
    this->setYear(year);
    this->setMonth(month);
}

void Periodical:: print()const {
    cout <<
    " " << setw(AVAILABLE_COL_WIDTH) << (totalCopies - checkedOutCopies) <<
    " " << setw(YEAR_COL_WIDTH) << year <<
    " " << right << setw(MONTH_COL_WIDTH) << month << left <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) << endl;
}

void Periodical:: printHeader() const {
    cout << "Periodical:" << endl;
    cout <<
        setw(AVAILABLE_COL_WIDTH+2) << "AVAIL" <<
        setw(YEAR_COL_WIDTH+1) << "YEAR" <<
        setw(MONTH_COL_WIDTH+1) << "MONTH" <<
        setw(TITLE_COL_WIDTH+1) << "TITLE" << endl;
    
    
}
