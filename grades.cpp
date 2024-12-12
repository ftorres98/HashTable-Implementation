// Name: Fernando Torres
// USC NetID: torresfe
// CSCI 455 PA5
// Fall 2021

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

#include <string>

//#include <unordered_set>

using namespace std;

/**
 * prints out a brief command summary
 * 
 */
void printCmdSummart();

/**
 * insertToTable inserts a pair of (key, value) into the table grades. If student already 
 * present then it prints out a statement saying just that.
 * 
 * @param grades 
 */
void insertToTable(Table* &grades);

/**
 * changeScore changes the score of a student. If student not present then it prints out
 * a statement saying just that.
 * 
 * @param grades 
 */
void changeScore(Table* &grades);

/**
 * lookupName prints out the score associated with the student. If student not present 
 * then it prints a statement saying just that.
 * 
 * @param grades 
 */
void lookupName(Table* &grades);

/**
 * removeFromTable removes the student and their grade from the table. If student not
 * present then it prints a statement saying just that.
 * 
 * @param grades 
 */
void removeFromTable(Table* &grades);

/**
 * doLoop is in charge of reading in the commands inputed by user in the command line. 
 * It will keep asking for the command until keepgoing is false;
 * 
 * @param grades 
 */
void doLoop(Table* &grades);

int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }
   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*

   doLoop(grades);


   return 0;
}

void doLoop(Table* &grades){
   string command;
   bool keepgoing = true;

   do{
      cout << "cmd>";
      cin >> command;

      if(command == "insert"){
         insertToTable(grades);
      }
      else if(command == "change"){
         changeScore(grades);
      }
      else if(command == "lookup"){
         lookupName(grades);
      }
      else if(command == "remove"){
         removeFromTable(grades);
      }
      else if(command == "print"){
         grades->printAll();
      }
      else if(command == "size"){
         cout << grades->numEntries() << endl;
      }
      else if(command == "stats"){
         grades->hashStats(cout);
      }
      else if(command == "help"){
         printCmdSummart();
      }
      else if(command == "quit"){
         keepgoing = false;
      }
      else{
         cout << "ERROR: invalid command" << endl;
         printCmdSummart();
      }

   } while (keepgoing);
}

void printCmdSummart(){
   cout << "Valid commands:" <<endl;
   cout << "insert [name] [score] (insert name and score in the grade table)" << endl;
   cout << "change [name] [score] (change the score for name)" << endl;
   cout << "lookup [name] (lookup name and print their score)" << endl;
   cout << "remove [name] (remove this student)" << endl;
   cout << "print (print all names and scores in the table)" << endl;
   cout << "size (prints out the number of entries in table)" << endl;
   cout << "stats (prints out statistics about hash table)" << endl;
   cout << "help (prints out command summary)" << endl;
   cout << "quit (exists the program)" << endl;
}

void insertToTable(Table* &grades){
   string key;
   int value;
   cin >> key;
   cin >> value;
   bool insertSuccess = grades->insert(key,value);
         if(!insertSuccess){
            cout << key << " is already present." << endl;
         }
}

void changeScore(Table* &grades){
   string key;
   int value;
   cin >> key;
   cin >> value;
   int * num = grades->lookup(key);
   if(num == NULL){
      cout << key << " is not present." << endl;
   }
   else{
      *num = value;
   }
}

void lookupName(Table* &grades){
   string key;
   cin >> key;
   int * num = grades->lookup(key);
   if(num == NULL){
      cout << key << " is not present." << endl;
   }
   else{
      cout << *num << endl;
   }
}

void removeFromTable(Table* &grades){
   string key;
   cin >> key;
   bool removeSuccess = grades ->remove(key);
         if(!removeSuccess){
            cout << key << " is not present." << endl;
         }
}