//-----------------------------------------------------------------------------
// HashTable class: is a class which is a hash table container class. It is
// responsible for holding different types of hashable data.
//
// Assumptions:
// - The keys may only be chars from A - Z, inclusive.
// - Values from be a derived class of Hashable.
//-----------------------------------------------------------------------------

#include "hashtable.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: A hashtable is constructed. The implementation uses and array, and
    intializes all values to be null to start.
 Pre: Default value for initial is 71 (a prime number).
 ----------------------------------------------------------------------------*/
HashTable::HashTable(int initial) {
    table = new Hashable*[initial];
    tableSize = initial;
    elementCount = 0;
    for (int i = 0; i< tableSize; i++){
        table[i] = NULL;
    }
}
/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: All elements are iterated over and delete is called.
 Post: The hashtable and all members have been freed from memory.
 ----------------------------------------------------------------------------*/
HashTable::~HashTable() {
    for (int i = 0; i < tableSize; i++)
    {
        if (table[i] != NULL)
        {
            delete table[i];
        }
        table[i] = NULL;
    }
    delete []table;
}

/*---------------------------------------------------------------------------
 ===== Add
 Descripton: Adds a Hashable value to the hashmap.
 Pre: char key is in range [A-Z].
 Post: if false is returned, the value could not be added to the hashtable.
 ----------------------------------------------------------------------------*/
bool HashTable::add(char key, Hashable* value) {
    int index = indexOf(key);
    if(index < 0) return false; // invalid hash, cant be added.
    
    table[index] = value;
    elementCount++;
    return true;
}

/*---------------------------------------------------------------------------
 ===== Get
 Descripton: Retrieves a value from the hashtable by key.
 Pre: char key is in range [A-Z].
 Post: NULL or Hashable* is returned. NULL if the value is not in table.
 ----------------------------------------------------------------------------*/
Hashable* HashTable::get(char key) const {
    int index = indexOf(key);
    if(index < 0) return NULL;
    return table[index];
}

/*---------------------------------------------------------------------------
 ===== Remove
 Descripton: Removes a values from the hashtable, and returns it to the user.
 Pre: char key is in range [A-Z].
 Post: NULL or Hashable* is returned. NULL if item is not in table. Hashable*
    is item that was removed.
 ----------------------------------------------------------------------------*/
Hashable* HashTable::remove(char key) {
    int index = indexOf(key);
    if(index < 0) return NULL;
    Hashable* toRemove = table[index];
    
    elementCount--;
    table[index] = NULL;
    return toRemove;
}

/*---------------------------------------------------------------------------
 ===== Is Empty?
 Descripton: Returns whether the hashtable is empty or not.
 Post: true if empty, false otherwise.
 ----------------------------------------------------------------------------*/
bool HashTable::isEmpty() const {
    return elementCount == 0;
}

/*---------------------------------------------------------------------------
 ===== Contains Item?
 Descripton: Returns whether the hashtable contains a specific value associated
    with char key.
 Pre: char key is in range [A-Z].
 Post: true if value associated with key, false otherwise.
 ----------------------------------------------------------------------------*/
bool HashTable::contains(char key) const {
    return get(key) != NULL;
}

/*---------------------------------------------------------------------------
 ===== Size
 Descripton: Returns the amount of values associated with unique keys in the
    hashtable.
 Post: Returns the int amount of elements in the table.
 ----------------------------------------------------------------------------*/
int HashTable::size() const {
    return elementCount;
}

/*---------------------------------------------------------------------------
 ===== Index to Insert | Retrieve (Private helper)
 Descripton: Given a key, it will return the index associated with the key. If
    used in getting, it returns the index where the value associated with the
    key is stored.
 Pre: char key is in range [A-Z]
 Post: positive integer, or -1 if not found or error happened.
 ----------------------------------------------------------------------------*/
int HashTable::indexOf(char key) const {
    
    //invalid key
    if(!('A' <= key && key <= 'Z')) return -1;
    
    int index = (key - 'A') % tableSize;
    
    //Quadratic probing, closed hashing. Stop when the hash is equal to the
    //  hash of the value.
    for(int collisions = 1;
        table[index] != NULL && table[index]->hash() != key;
        collisions++)
    {
        index = index + (collisions*collisions) % tableSize;
    }
    return index;
}
