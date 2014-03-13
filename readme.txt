==============================================================
==                                                          ==
==                ----- Lab 4 Readme -----                  ==
==     ----- Developers: Magda Grzmiel & Tom Petit -----    ==
==                ----- Winter 2014 -----                   ==
==                                                          ==
==============================================================



==============================================================
1. Describe the state of your program, exactly what works and
   what does not work. 
==============================================================
The program is completely functional as far as we know. All
functionality required by the lab is implemented.


==============================================================
2. List your hash table(s): briefly what they are used for
   and file found in. (Include any factories that are 
   essentially hash tables.) 
==============================================================
The hashtable is implemented in hashtable.cpp. The implemented
hashtable is used inside item & transaction factory. They are
used in the factories so that the specific type of item or 
transaction may be returned.

An STL map is also used to store the users in manager.

An array that resembles a hashtable is used inside 
ItemCollection to allow different types to be stored.


==============================================================
3. Describe which file and which function you read the book
   data, high level function call, i.e., how/where it gets 
   into your book collections. 
==============================================================
1. The main instantiates an istream& to the book data.
2. The main passes this data to manager.buildItems
3. While itemData not EOF:
4.    pass itemData to itemFactory.create
5.    create reads the character, and uses it as key in 
      hashtable to retrieve item
6.    pass the itemData to item->create
7.    item instantiates itself (by using default constructor 
      and setting up only item type) and returns 
8.    in manager class, if the already created item is not  
      NULL, the item is initialized by calling the initialized 
      method on it and passing istream as parameter.
9.    then manager inserts created item into itemcollection 
      if a valid item is returned.


==============================================================
4. Describe which file and which function you read the command
   data, high level function call, i.e., how/where you perform
   the commands/transactions. 
==============================================================
1. The main instantiates an istream& to the command data.
2. The main passes this data to manager.processTransactions
3. While commandData not EOF:
4.    pass commandData to transactionFactory.createTransaction
5.    create reads the character, and uses it as key in 
      hashtable to retrieve correct transaction.
6.    pass the commandData to transaction->create
7.    transaction instantiates itself and returns
8.    return the instantiated transaction to the manager
9.    manager calls execute on the transaction if it's not 
      NULL.
10.   transaction is deleted after execution.


=============================================================
5. Describe any dirty little secrets (e.g., switch used, or
   if-else-if, etc.) If you feel they do not violate the
   open-closed design principle, explain.
==============================================================
Everything is beautiful. :)


=============================================================
6. Describe anything you are particularly proud of.
==============================================================

We are proud that we implemented an AVL tree & a HashTable 
class implemented as separate c++ classes.

Also all the blood, sweat, coffee, & tears that went into 
this assignment.(~30 hours)




