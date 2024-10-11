#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
//#include "LinkedList.cpp"

//constructor 
Stack::Stack(){

}

//destructor
Stack::~Stack(){
  list.~LinkedList();
}


void Stack::push(double val){
  list.appendListNode(val);
}

void Stack::pop(){
  int length1;
  length1=list.length();
  list.removeListNodeN(length1);
}

double Stack::top() const{
  ListNode *head2=list.getHead();
  ListNode *current = head2;
  while(current->next != nullptr){
    current = current->next;
  }
  return current->value;
}

bool Stack::isEmpty() const{
  return list.isEmpty();
}

void Stack::displayStack() const{
  list.displayList();
}