
//-----------------------------------------------------------------------------
// class Periodical
//
// Represents a patron that is visiting the library and performing some
// commands. They are represented by a name and a unique identification
// number. They also contain a history of all commands related to them.
//
// Assumptions:
//  -- user id will be set as something unique
//-----------------------------------------------------------------------------

#ifndef PERIODICAL_H
#define PERIODICAL_H
#include "item.h"
#include <string>

class Periodical : public Item {
public:
    Periodical(string title); // Constructor
    ~Periodical(); // Destructor
 
    int getYear(); // accessor 
    int getMonth(); // accessor

    void setYear(int y); // mutator
    void setMonth(int m); // mutator

    int compare(Item*); //comparator
private:
    int month;
    int year;
};

#endif