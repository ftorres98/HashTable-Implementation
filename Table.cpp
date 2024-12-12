// Name: Fernando Torres
// USC NetID: torresfe
// CSCI 455 PA5
// Fall 2021

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashTable = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
   numOfEntries = 0;
}


Table::Table(unsigned int hSize) {
   hashTable = new ListType[hSize]();
   hashSize = hSize;
   numOfEntries = 0;
}


int * Table::lookup(const string &key) {
   return listLookup(hashTable[hashCode(key)], key);
}


bool Table::remove(const string &key) {
   bool removeSuccess = listRemove(hashTable[hashCode(key)], key);
   if(removeSuccess){
      numOfEntries--;
      return true;
   }
   return false;
}


bool Table::insert(const string &key, int value) {
   bool insertSuccess = listInsert(hashTable[hashCode(key)], key, value);
   if(insertSuccess){
      numOfEntries++;
      return true;
   }
   return false;
}


int Table::numEntries() const {
   return numOfEntries;
}


void Table::printAll() const {
   for(int i = 0; i < hashSize; i++){
      printList(hashTable[i]);
   }
}


void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numOfEntries << endl;
   out << "number of non-empty buckets: " << nonEmptyBuckets() << endl;
   out << "longest chain: " << longestChain() << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

int Table::nonEmptyBuckets() const{
   int count = 0;
   for(int i = 0; i < hashSize; i++){
      if(hashTable[i] != NULL){
         count++;
      }
   }
   return count;
}

int Table::longestChain() const {
   int longest = 0;
   for(int i = 0; i < hashSize; i++){
      int curr = 0;
      ListType p = hashTable[i];
      while(p != NULL){
         curr++;
         p = p->next;
      }
      if(curr > longest){
         longest = curr;
      }
   }
   return longest;
}

