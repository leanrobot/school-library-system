//---------------------------------------------------------------------------
// lab4.cpp
//---------------------------------------------------------------------------
// This code tests the functionality of the classes to perform a few
// operation in the library, such as: check out, return, display and history.
//
// Assumptions:
//   -- text files "data4patrons.txt" and "data4books.txt" and
//      "data4commands.txt" exist and are formatted as described
//---------------------------------------------------------------------------

#include "manager.h"
#include <fstream>
#include <iostream>
#include "itemtree.h"
#include "youth.h"
using namespace std;

int main() {

	Manager manager;

	// check if the file with users exists
    //ifstream infile1("testpatrons.txt");
	ifstream patronData("data4patrons.txt");
	if (!patronData) {
		cout << "File could not be opened." << endl;
		return 1;
	}
    
    // build users
	manager.buildUsers(patronData);
    
    
	// check if the file with items exists
    //ifstream infile2("testbooks.txt");
	ifstream itemData("data4books.txt");
	if (!itemData) {
		cout << "File could not be opened." << endl;
		return 1;
	}
    
    //build items
	manager.buildItems(itemData);
    
	// check if the file with transactions exists
    //ifstream infile3("testcommands.txt");
	ifstream commandData("data4commands.txt");
	if (!commandData) {
		cout << "File could not be opened." << endl;
		return 1;
	}
    
    // process transactions
	manager.processTransaction(commandData);
	
    return 0;
    
}

