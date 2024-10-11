#include "LinkedList.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DBL_EPS 0.00001

LinkedList::LinkedList(){
  head=nullptr;
}
// destructor deallocates all nodes 
LinkedList::~LinkedList() {
   removeList();
}


void LinkedList::removeListNodeN(int N){
  struct ListNode* current = head;
	struct ListNode* prev = NULL;
	int counter =1;

	/* If the node to be deleted is the head node */
	if (current != NULL && N==1) {
		head = current->next;
		free(current);
		return;
	}

	/* Traverse the list to find the node to be deleted */
	while (current != NULL && counter!=N) {
		prev = current;
		current = current->next;
		counter++;
	}

	/* If the node to be deleted is found, delete it */
	if (current != NULL) {
		prev->next = current->next;
		free(current);
	}
}


bool LinkedList::isEmpty() const{
    // If head is NULL, the list is empty
    // Otherwise, it's not empty
    return (head == nullptr);
}

void LinkedList::displayList() const{
	const struct ListNode* current = NULL;
	current = head;
	while (current != NULL) {
		printf("%lf ", current->value);
		current = current->next;
	}
	printf("\n");
}

int LinkedList::length() const{
  int count = 0;
	const struct ListNode* current = head;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}


void LinkedList::insertListNode(double val){
  struct ListNode* newListNode = new ListNode;
		newListNode->value = val;
		newListNode->next = head;
    head= newListNode;
}


void LinkedList::removeListNode(double val){
  struct ListNode* current = head;
	struct ListNode* prev = NULL;

	/* If the node to be deleted is the head node */
	if (current != NULL && fabs(current->value - val) < DBL_EPS) {
		head = current->next;
		free(current);
		return;
	}

	/* Traverse the list to find the node to be deleted */
	while (current != NULL && fabs(current->value - val) > DBL_EPS) {
		prev = current;
		current = current->next;
	}

	/* If the node to be deleted is found, delete it */
	if (current != NULL) {
		prev->next = current->next;
		free(current);
	}
	else {
		printf("ListNode with value %lf not found in the list.\n", val);
	}
}


void LinkedList::appendListNode(double val){
  struct ListNode* newListNode = NULL;
	newListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (newListNode != NULL) {
		newListNode->value = val;
		newListNode->next = NULL;
	}
	if (newListNode) {

		/* If the list is empty, make the new node the head of the list */
		if (head == NULL) {
			head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the last node */
		struct ListNode* current = head;
		while (current->next != NULL) {
			current = current->next;
		}

		/* Insert the new node after the last node */
		current->next = newListNode;
	}
	else 
	{
		printf("Memory allocation failed.\n");
	}

}

void LinkedList::removeList(){
  ListNode* current = head;
	while (current != nullptr) {
		ListNode* temp = current;
		current = current->next;
		delete(temp);
	}
  head = nullptr;
}

ListNode* LinkedList::getHead() const{
  return head;
}