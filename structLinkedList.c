#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DBL_EPS 0.00001

struct ListNode {
	double value;
	struct ListNode* next;
};

struct LinkedList {
	struct ListNode* head;
};


struct LinkedList* createLinkedList();
void freeLinkedList(struct LinkedList* list);
int isEmpty(const struct LinkedList* list);
void displayList(const struct LinkedList* list);
int length(const struct LinkedList* list);
void insertListNode(struct LinkedList* list, double val);
void removeListNode(struct LinkedList* list, double val);
void appendListNode(struct LinkedList* list, double val); 
struct ListNode * createNode(double val);
struct LinkedList* createLinkedList();



int main() {
	/* Create a new linked list */
	struct LinkedList* list;
	list = createLinkedList();
	if (list == NULL) {
		printf("Failed to create linked list.\n");
		return 1;
	}

	/* Insert some nodes at the front of the linked list */
	insertListNode(list, 3);
	insertListNode(list, 5);
	insertListNode(list, 7);
	insertListNode(list, 2);
	insertListNode(list, 6);

	/* Print the linked list */
	printf("Linked list: ");
	displayList(list);

	/* Remove a node from the linked list */
	removeListNode(list, 5);

	/* Append a node to the end of the linked list */
	appendListNode(list, 9);

	/* Print the modified list*/
	printf("Modified linked list: ");
	displayList(list);

	/* Remove nodes from list*/
	removeListNode(list, 7);
	removeListNode(list, 2);
	removeListNode(list, 9);

	/* Print the modified list*/
	printf("Modified linked list: ");
	displayList(list);

	/* Free memory allocated for the linked list */
	freeLinkedList(list);

	return 0;
}


int isEmpty(const struct LinkedList* list);

/* Function to initialize a new linked list */
struct LinkedList* createLinkedList() {
	struct LinkedList* list = NULL;
	list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
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

int isEmpty(const struct LinkedList* list) {
	return (list->head == NULL);
}

/* Function to print the linked list */
void displayList(const struct LinkedList* list) {
	const struct ListNode* current = NULL;
	current = list->head;
	while (current != NULL) {
		printf("%lf ", current->value);
		current = current->next;
	}
	printf("\n");
}

/* Recursive function to display the linked list */
void displayListRec(const struct ListNode* node) {
	if (node == NULL) {
		printf("\n");
		return;
	}
	printf("%lf ", node->value);
	displayListRec(node->next);
}

/* Function to create a Node */
struct ListNode * createNode(double val)
{
	struct ListNode* newListNode = NULL;
	newListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (newListNode != NULL) {
		newListNode->value = val;
		newListNode->next = NULL;
	}
	return newListNode;
}

/* Function to insert a new node with the given value in ascending order */
void insertListNode(struct LinkedList* list, double val) {
	struct ListNode *newListNode = newListNode = createNode(val);
	if (newListNode)
	{
		/* If the list is empty or the new node's value is less than the value of the head node,
		   insert the new node at the front. */
		if (list->head == NULL || val < list->head->value)
		{
			newListNode->next = list->head;
			list->head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the correct position to insert the new node. */
		struct ListNode* current = list->head;
		while (current->next != NULL && current->next->value < val)
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


/* Function to remove the node with the given value from the linked list */
void removeListNode(struct LinkedList* list, double val) {
	struct ListNode* current = list->head;
	struct ListNode* prev = NULL;

	/* If the node to be deleted is the head node */
	if (current != NULL && fabs(current->value - val) < DBL_EPS) {
		list->head = current->next;
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

/* Function to append a new node with the given value to the end of the linked list */
void appendListNode(struct LinkedList* list, double val) {
	struct ListNode* newListNode = NULL;
	newListNode = createNode(val);
	if (newListNode) {

		/* If the list is empty, make the new node the head of the list */
		if (list->head == NULL) {
			list->head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the last node */
		struct ListNode* current = list->head;
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

/* Function to get the length of the linked list */
int length(const struct LinkedList* list) {
	int count = 0;
	const struct ListNode* current = list->head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}