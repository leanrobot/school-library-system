==============================================================
==                                                          ==
==                ----- Lab 4 Readme -----                  ==
==     ----- Developers: Magda Grzmiel & Tom Petit -----    ==
==                ----- Winter 2014 -----                   ==
==                                                          ==
==============================================================

1. Describe the state of your program, exactly what works and
    what does not work. 
==============================================================

The program is completely functional as far as we know. All
functionality required by the lab is implemented.

2. List your hash table(s): briefly what they are used for
    and file found in. (Include any factories that are 
    essentially hash tables.) 
==============================================================

The hashtable is implemented in hashtable.cpp. The implemented
hashtable is used inside item & transaction factory. they are
used in the factories so that the specific type of item or 
transaction may be returned.

an STL map is also used to store the users in manager.

an array that resembles a hashtable is used inside ItemCollection.
to allow different types to be stored.

3. Describe which file and which function you read the book
    data, high level function call, i.e., how/where it gets 
    into your book collections. 
==============================================================

1. The main instantiates an istream& to the book data.
2. the main passes this data to manager.buildItems
3. while itemData not EOF:
4.    pass itemData to itemFactory.create
5.    create reads the character, and uses it as key in hashmap
      to retrieve item
6.    pass the itemData to item->create
7.    item instantiates itself and returns 
8.    return item to manager
9.    manager inserts into itemcollection if a valid item is
      returned.

4. Describe which file and which function you read the command
    data, high level function call, i.e., how/where you perform
    the commands/transactions. 
==============================================================



5. Describe any dirty little secrets (e.g., switch used, or
    if-else-if, etc.) If you feel they do not violate the
    open-closed design principle, explain.
==============================================================



6. Describe anything you are particularly proud of.
==============================================================




