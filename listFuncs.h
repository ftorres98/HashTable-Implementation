// Name: Fernando Torres
// USC NetID: torresfe
// CSCI 455 PA5
// Fall 2021


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

/**
 * listInsert inserts a new node with theKey and theValue to the front of the list 
 * if theKey is not yet present. It then returns true if it was able to 
 * insert and false if theKey was already present and the list remains unmodified.
 * 
 * @param list
 * @param theKey
 * @param theValue
 * @return true 
 * @return false 
 */
bool listInsert(ListType &list, const std::string &theKey, int theValue);

/**
 * listRemove removes node with theKey from the list.
 * It then returns true if it was able to remove the node and 
 * false if theKey was not present and the list remains unmodified.
 * 
 * @param list
 * @param theKey 
 * @return true 
 * @return false 
 */
bool listRemove(ListType &list, const std::string &theKey);

/**
 * listLookup returns the address of the value that goes with theKey.
 * It returns NULL if theKey is not present.
 * 
 * @param list 
 * @param theKey 
 * @return int* 
 */
int *listLookup(ListType &list, const std::string &theKey);

/**
 * printList prints all the entries from the list.
 * 
 * @param list 
 */
void printList(ListType list);



// keep the following line at the end of the file
#endif
