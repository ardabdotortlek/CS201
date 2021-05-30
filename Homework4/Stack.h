#pragma once
#include <iostream>
#include "List.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

class Stack{
public:
   Stack();
   Stack(const Stack& cStack);
   ~Stack();

   bool isEmpty() const;
   bool push(double newItem);
   bool pop();
   bool pop(double& stackTop);
   bool getTop(double& stackTop) const;

private:
   List aList;
};
