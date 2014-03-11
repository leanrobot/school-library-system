#include "periodical.h"
#include <iomanip>

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Periodical class.
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
Periodical:: Periodical(){
    itemType = 'P';
}

/*---------------------------------------------------------------------------
 ===== getMonth
 Descripton: Retrieve the month of the book's publishing
 Pre:
 Post: Returns the month of publishing
 ----------------------------------------------------------------------------*/
int Periodical:: getMonth() const{
    return this->month;
}

/*---------------------------------------------------------------------------
 ===== setMonth
 Descripton: Set up the month of publishing
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
void Periodical:: setMonth(int newMonth){
    this->month = newMonth;
}

/*---------------------------------------------------------------------------
 ===== operator<
 Descripton: Overloaded less than operator. Determine if this periodical
 object is less than the other periodical object.
 Pre:
 Post: Return true if this periodical is less than other, false otherwise
 ----------------------------------------------------------------------------*/
bool Periodical::operator< (const Item& item) const {
    if(item.getItemType() != itemType) return false;

    // cast the item object to the periodical object
	const Periodical& otherPeriodical = static_cast<const Periodical&>(item);
    
    // first compare the years, if this periodical year is less than other
    // periodical year, return true
	if (this->year < otherPeriodical.year) {
		return true;
	}
    
    // if the years are equal, comapre the months
	if (this->year == otherPeriodical.year) {
        // if this periodical moth is less than other, return trus
		if (this->month < otherPeriodical.month) {
			return true;
        // if the moths are equal
		} else if (this->month == otherPeriodical.month) {
            // compare titles
			if (this->title.compare(otherPeriodical.title) < 0)
				return true;
		}
	}
    return false;
}

/*---------------------------------------------------------------------------
 ===== operator>
 Descripton: Overloaded greater than operator. Determine if this periodical 
 object is grater than the other periodical object.
 Pre:
 Post: Return true if this periodical is greater than other, false otherwise.
 ----------------------------------------------------------------------------*/
bool Periodical::operator> (const Item& item) const {
    return !(*this < item) && *this != item;
}

/*---------------------------------------------------------------------------
 ===== operator==
 Descripton: Overloaded equal operator. Determine if two periodical objects
 are equal.
 Pre:
 Post: Return true if two periodicals objects are equal, false otherwise,
 ----------------------------------------------------------------------------*/
bool Periodical:: operator== (const Item& item) const{
    if(item.getItemType() != itemType) return false;

    const Periodical& otherPeriodical = static_cast <const Periodical&> (item);

    return ((this -> title.compare(otherPeriodical.title)==0)
            && this->month == otherPeriodical.month
            && this->year == otherPeriodical.year);
}

/*---------------------------------------------------------------------------
 ===== operator!=
 Descripton: Overloaded not equal operator. Determine if two periodical
 objects are not equal.
 Pre:
 Post: Return true if two periodicals objects are not equal, false otherwise
 ----------------------------------------------------------------------------*/
bool Periodical:: operator!= (const Item& item) const{
    return !(*this == item);
}

/*---------------------------------------------------------------------------
 ===== create
 Descripton: Create periodical object.
 Pre:
 Post: Return periodical object
 ----------------------------------------------------------------------------*/
Item* Periodical:: create(){
    Item* newPeriodical = new Periodical;
    return newPeriodical;
}

/*---------------------------------------------------------------------------
 ===== initialize
 Descripton: Read the data from file and initialized the periodical object
 when new periodical is added to the library
 Pre:
 Post: Return periodical object
 ----------------------------------------------------------------------------*/
void Periodical::initialize(istream& infile) {
    string title;
    int month, year;
    
    getline(infile, title, ',');   // input title, looks for comma terminator
    infile >> month;               // iput the month,
    infile >> year;                // then the year
    infile.get();                  // discard the newline character

    
    // set up title, month and year of this periodical object
    this->setTitle(title);
    this->setMonth(month);
    this->setYear(year);
}

/*---------------------------------------------------------------------------
 ===== initializePartial
 Descripton: Read the data from file and initialized the periodical object
 to perform given transaction on it
 Pre:
 Post:Return periodical object
 ----------------------------------------------------------------------------*/
void Periodical::initializePartial(istream& infile) {
    string  title;
    int year, month;
    
    infile.get(); infile.get();  // discard the 'H' char and extra space
    infile >> year;              // input the month,
    infile >> month;             // then the year
    infile.get();                // discard the extra space
    getline(infile, title, ','); // read the title
    infile.get();                // discard the newline character
    
    // set up title, month and year of this periodical object
    this->setTitle(title);
    this->setYear(year);
    this->setMonth(month);
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information about the periodical object
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
void Periodical:: print()const {
    cout <<
    " " << setw(AVAILABLE_COL_WIDTH) << (totalCopies - checkedOutCopies) <<
    " " << setw(YEAR_COL_WIDTH) << year <<
    " " << right << setw(MONTH_COL_WIDTH) << month << left <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) << endl;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print header for the print method
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
void Periodical:: printHeader() const {
    cout << "Periodical:" << endl;
    cout <<
        setw(AVAILABLE_COL_WIDTH+2) << "AVAIL" <<
        setw(YEAR_COL_WIDTH+1) << "YEAR" <<
        setw(MONTH_COL_WIDTH+1) << "MONTH" <<
        setw(TITLE_COL_WIDTH+1) << "TITLE" << endl;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information about the periodical which are used in the
 print method in the history transaction object
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
void Periodical:: display()const {
    cout <<
    " " << setw(YEAR_COL_WIDTH) << year <<
    " " << right << setw(MONTH_COL_WIDTH) << month << left <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) << endl;
}

