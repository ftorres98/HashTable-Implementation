// Name: Fernando Torres
// USC NetID: torresfe
// CSCI 455 PA5
// Fall 2021


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

//helper function
/** 
 * lookupNode looks up a node with theKey and returns a 
 * pointer to that node. If it is not found it returns NULL.
 * 
 * @param list 
 * @param theKey 
 * @return ListType 
 */
ListType lookupNode(ListType &list, const std::string &theKey);

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

bool listInsert(ListType &list, const string &theKey, int theValue){
   if(lookupNode(list,theKey) == NULL){
      list = new Node(theKey, theValue, list);  
      return true;
   }
   return false;
}

bool listRemove(ListType &list, const string &theKey){

   ListType nodetoRem = lookupNode(list,theKey);

   //if the node doesn't exist
   if(nodetoRem == NULL){
      return false;
   }

   //if it is the front node
   if(list == nodetoRem){
      list = list->next;
      delete nodetoRem;
   }
   //anywhere else in the list
   else{
      ListType p = list;

      while(p->next != nodetoRem){
         p = p->next;
      }
      p->next = p->next->next;
      delete nodetoRem;
   }

   return true;
}

int * listLookup(ListType &list, const string &theKey){
   ListType p = lookupNode(list, theKey);
   if(p != NULL){
      return &p->value;
   }
   return NULL;
}


void printList(ListType list){
   ListType p = list;
   if(p == NULL){
      return;
   }
   while (p != NULL)
   {
      cout << p->key << " " << p->value << endl;
      p = p->next;
   }
   
}

ListType lookupNode(ListType &list, const string &theKey){
   ListType p = list;

   if(p == NULL){
      return NULL;
   }

   while (p != NULL)
   {
      if(p->key == theKey){
         return p; 
      }

      p = p->next;
   }

   return NULL;
}

