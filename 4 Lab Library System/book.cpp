#include "book.h"

Book:: Book(): Item(){
}


//Book:: Book(char itemType, string title, string author, int year)
//        :Item (itemType, title, year){
//    this->author = author;
//};

string Book:: getAuthor()const {
    return author;
}

void Book:: setAuthor(string newAuthor){
    this->author = newAuthor;
}

