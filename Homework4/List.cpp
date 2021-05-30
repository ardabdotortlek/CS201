#include <iostream>
#include "List.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

/**
    Constructor
*/
List::List(){
    this->size = 0;
    this->head = NULL;
}

/**
    Copy Constructor
*/
List::List(const List& cList){
    this->size = cList.size;

    if(cList.head == NULL){
        this->head = NULL;
    }

    else{
        this->head = new ListNode;
        this->head->item = cList.head->item;
        ListNode* newPtr = head;

        for(ListNode* ptr = cList.head->next; ptr != NULL; ptr = ptr->next){
            newPtr->next = new ListNode;
            newPtr->next->item = ptr->item;
            newPtr = newPtr->next;
        }

        newPtr->next = NULL;
    }
}

/**
    Destructor
*/
List::~List(){
    while(!isEmpty())
        remove(1);
}

/**
    @return true if the list is empty
*/
bool List::isEmpty() const{
    return this->size == 0;
}

int List::getLength() const{
    return this->size;
}

/**
    @param index
    @return pointer whose index is given as parameter
*/
List::ListNode* List::find(int index) const{
    if ( (index < 1) || (index > getLength()) )
      return NULL;

   else{
      ListNode *ptr = head;
      for (int i = 1; i < index; ++i)
         ptr = ptr->next;
      return ptr;
   }

}

/**
    @param index,dataItem
    @return true if the operation is successful
*/
bool List::retrieve(int index, double& dataItem) const{
    if ( (index < 1) || (index > getLength()) )
      return false;

    ListNode* cur = find(index);
    dataItem = cur->item;
    return true;
}

/**
    @param index,newItem
    @return true if the operation is successful
*/
bool List::insert(int index, double newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   ListNode *newPtr = new ListNode;
   size = newLength;
   newPtr->item = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ListNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

}

/**
    @param index
    @return true if the operation is successful
*/
bool List::remove(int index) {

   ListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      ListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;

}















