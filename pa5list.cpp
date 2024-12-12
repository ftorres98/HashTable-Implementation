// Name: Fernando Torres
// USC NetID: torresfe
// CSCI 455 PA5
// Fall 2021

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
   ListType p = new Node("hi", 2);

   cout << "Creating first node:" << endl;
   printList(p);

   cout << "After inserting:" << endl;
   listInsert(p,"hello", 10);
   printList(p);

   cout << "After removing something that isnt there:" << endl;
   listRemove(p,"ciao");
   printList(p);

   /*
   cout << "After removing \"hello\":" << endl;
   listRemove(p,"hello");
   printList(p);
   */

   /*
   cout << "After removing \"hi\":" << endl;
   listRemove(p,"hi");
   printList(p);
   */

   cout << "After inserting:" << endl;
   listInsert(p,"hola", 200);
   printList(p);

   cout << "After removing \"hi\":" << endl;
   listRemove(p,"hi");
   printList(p);


   delete p;

   return 0;
}
