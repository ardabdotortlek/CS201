#include <iostream>
#include "Stack.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

/**
    Constructor
*/
Stack::Stack(){

}

/**
    Copy Constructor
*/
Stack::Stack(const Stack& cStack){
    this->aList = cStack.aList;
}

/**
    Destructor
*/
Stack::~Stack(){

}

/**
    @return true if the stack is empty
*/
bool Stack::isEmpty() const {
   return aList.isEmpty();
}

bool Stack::getTop(double& stackTop) const {
   return aList.retrieve(1, stackTop);
}

/**
    Adds new item to the top of the stack
    @param newItem
    @return true if operation is successful
*/
bool Stack::push(double newItem){
     return aList.insert(1, newItem);
}

/**
    Deletes the item at the top
    @return true if operation is successful
*/
bool Stack::pop() {
    return aList.remove(1);
}

/**
    Deletes the item at the top
    @param stackTop
    @return true if operation is successful
*/
bool Stack::pop(double& stackTop) {
   if (aList.retrieve(1, stackTop))
      return aList.remove(1);
   else
      return false;
}
