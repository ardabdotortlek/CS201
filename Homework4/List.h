#pragma once
#include <iostream>
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

class List{
public:
    List();
    List(const List& cList);
    ~List();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index,double& dataItem) const;
    bool insert(int index, double newItem);
    bool remove(int index);

private:
    struct ListNode{
        double item;
        ListNode* next;
    };

    int size;
    ListNode* head;

    ListNode* find(int index) const;

};
