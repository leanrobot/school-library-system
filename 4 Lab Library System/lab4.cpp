//---------------------------------------------------------------------------
// lab4.cpp
//---------------------------------------------------------------------------
// This code tests the functionality of the classes to perform a few
// operation in the library, such as: check out, return, display and history.
//
// Assumptions:
//   -- text files "users.txt" and "items.txt" and "transactios.txt" exist
//      and are formatted as described
//---------------------------------------------------------------------------

#include "manager.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	Manager manager;

	// check if the file with users exists
	ifstream infile1("data4patrons.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager.buildUsers(infile1);

    
    /*
	// check if the file with items exists
	ifstream infile2("items.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager.buildItems(infile2);

	// check if the file with transactions exists
	ifstream infile3("transactions.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager.processTransaction(infile3);
*/
	return 0;

}

