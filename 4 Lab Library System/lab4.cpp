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
#include "itemtree.h"
#include "youth.h"
using namespace std;

int main() {

	Manager manager;

	// check if the file with users exists
    //ifstream infile1("testpatrons.txt");
	ifstream infile1("testpatrons.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager.buildUsers(infile1);
    
    
	// check if the file with items exists
    //ifstream infile2("testbooks.txt");
	ifstream infile2("testbooks.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager.buildItems(infile2);
    
    //Test DisplayTransaction
    //manager.testTransactions();
    
	// check if the file with transactions exists
    //ifstream infile3("testcommands.txt");
	ifstream infile3("testcommands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager.processTransaction(infile3);
	return 0;
    
    /*
    //TEST ITEM COLLECTION
    ItemCollection ic;
    Item* one = new Youth("aTitle",  "aAuthor", 2000);
    Item* two = new Youth("aaadfds", "bAuthor", 2000);
    Item* three = new Youth("bbbb", "bAuthor", 2000);
    
    cout << "\none less than 2?" << (*one < *two) << endl;
    cout << "\none less than 2?" << (*two < *one) << endl;
    
    ic.insert(three);
    ic.insert(two);
    ic.insert(one);
    
    cout << "retrieve " <<  ic.retrieve(two) << endl;
    
    cout << endl;
    for(int i=0; i<ic.size(); i++) {
        Youth* it = static_cast<Youth*>(ic.retrieve(i));
        cout << it->getTitle() << " " << it->getAuthor()<< " " << it << endl;
    }

     */
}

