#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
private:
	LinkedList list;

public:
	Stack();
	~Stack();
	void push(double val);
	void pop();
	double top() const;
	bool isEmpty() const;
	void displayStack() const;
};

#endif // STACK_H


