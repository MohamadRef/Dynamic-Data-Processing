#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DBL_EPS 0.00001

typedef struct ListNode {
	double value;
	struct ListNode* next;
}ListNode;

typedef struct LinkedList {
	struct ListNode* head;
}LinkedList;


LinkedList* createLinkedList();
void freeLinkedList(LinkedList* list);
ListNode * createNode(double val);
void displayList(const LinkedList* list);
void insertListNode(LinkedList* list, double val); 
void appendListNode(LinkedList* list, double val);
LinkedList* InsertionListDescendingIter(const LinkedList* list);

void SelectionListDescendingRec(ListNode* current);
ListNode* findMax(ListNode* current, ListNode* maxNode);
void swapValues(ListNode* node1, ListNode* node2);


int main() {

	/*two tests referred to in problem*/
	/* you will probably want the make additional tests yourself*/

	/* Create a new linked list */
	struct LinkedList* list;
	list = createLinkedList();
	if (list == NULL) {
		printf("Failed to create linked list.\n");
		return 1;
	}

	/* Insert some nodes into the linked list */
	appendListNode(list, 88); 
	appendListNode(list, 23);
	appendListNode(list, 36);
	appendListNode(list, 17);
	appendListNode(list, 2);
	appendListNode(list, 63);
	appendListNode(list, 28);

	struct LinkedList* sortedlist;
	sortedlist = InsertionListDescendingIter(list);
	printf("Original linked list: \n");
	displayList(list);
	printf("Insertion sort sorted linked list: \n");
	displayList(sortedlist);
	printf("\n\n");
	/* Free memory allocated for the linked list */
	freeLinkedList(list);
	freeLinkedList(sortedlist);


	list = createLinkedList();
	if (list == NULL) {
		printf("Failed to create linked list.\n");
		return 1;
	}

	appendListNode(list, 88);
	appendListNode(list, 83);
	appendListNode(list, 45);
	appendListNode(list, 27);
	appendListNode(list, 91);
	appendListNode(list, 76);
	appendListNode(list, 62);
	printf("Original List \n");
	displayList(list);
	SelectionListDescendingRec(list->head);
	printf("Selection sort sorted List\n");
	displayList(list);
	/* Free memory allocated for the linked list */
	freeLinkedList(list);
	return 0;
}


/* Code to be written by the student should be added here*/




void SelectionListDescendingRec(ListNode* current) {
	if (current == NULL)
		return;

	ListNode* maxNode = findMax(current, current);
	swapValues(current, maxNode);

	SelectionListDescendingRec(current->next);
}


/* Function to append a new node with the given value to the end of the linked list */
void appendListNode(LinkedList* list, double val) {
	ListNode* newListNode = NULL;
	newListNode = createNode(val);
	if (newListNode) {

		/* If the list is empty, make the new node the head of the list */
		if (list->head == NULL) {
			list->head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the last node */
		ListNode* current = list->head;
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

/* Function to insert a new node with the given value in decending order */
void insertListNode(LinkedList* list, double val) {
	ListNode *newListNode;
	newListNode = createNode(val);
	if (newListNode)
	{
		/* If the list is empty or the new node's value is greater than the value of the head node,
		   insert the new node at the front. */
		if (list->head == NULL || val > list->head->value)
		{
			newListNode->next = list->head;
			list->head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the correct position to insert the new node. */
		ListNode* current = list->head;
		while (current->next != NULL && current->next->value > val)
		{
			current = current->next;
		}

		/* Insert the new node after the current node. */
		newListNode->next = current->next;
		current->next = newListNode;
	}
	else {
		printf("Memory allocation failed.\n");
	}
}


/* Function to initialize a new linked list */
LinkedList* createLinkedList() {
	LinkedList* list = NULL;
	list = (LinkedList*)malloc(sizeof(LinkedList));
	if (list != NULL) {
		list->head = NULL;
	}
	return list;
}

/* Function to free memory allocated for the linked list */
void freeLinkedList(struct LinkedList* list) {
	struct ListNode* current = list->head;
	while (current != NULL) {
		struct ListNode* temp = current;
		current = current->next;
		free(temp);
	}
	free(list);
}


ListNode * createNode(double val)
{
	ListNode* newListNode = NULL;
	newListNode = (ListNode*)malloc(sizeof(ListNode));
	if (newListNode != NULL) {
		newListNode->value = val;
		newListNode->next = NULL;
	}
	return newListNode;
}


void displayList(const struct LinkedList* list) {
	const struct ListNode* current = NULL;
	current = list->head;
	while (current != NULL) {
		printf("%lf ", current->value);
		current = current->next;
	}
	printf("\n");
}
