#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    double value;
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* head;
} LinkedList;

LinkedList* createLinkedList();
void freeLinkedList(LinkedList* list);
ListNode* createNode(double val);
void displayList(const LinkedList* list);
void appendListNode(LinkedList* list, double val);
LinkedList* InsertionListDescendingIter(const LinkedList* head);
void SelectionListDescendingRec(ListNode* current);
void swapValues(ListNode* node1, ListNode* node2);
ListNode* findMax(ListNode* start, ListNode* maxNode);

int main() {
    /* Create a new linked list for insertion sort */
    LinkedList* list1 = createLinkedList();
    if (list1 == NULL) {
        printf("Failed to create linked list.\n");
        return 1;
    }

    /* Insert some nodes into the first linked list */
    appendListNode(list1, 88);
    appendListNode(list1, 23);
    appendListNode(list1, 36);
    appendListNode(list1, 17);
    appendListNode(list1, 2);
    appendListNode(list1, 63);
    appendListNode(list1, 28);

    LinkedList* sortedList1 = InsertionListDescendingIter(list1);
    printf("Original linked list:\n");
    displayList(list1);
    printf("Insertion sort sorted linked list:\n");
    displayList(sortedList1);
    printf("\n");

    /* Free memory allocated for the first linked lists */
    freeLinkedList(list1);
    freeLinkedList(sortedList1);

    /* Create a new linked list for selection sort */
    LinkedList* list2 = createLinkedList();
    if (list2 == NULL) {
        printf("Failed to create linked list.\n");
        return 1;
    }

    /* Insert some nodes into the second linked list */
    appendListNode(list2, 88);
    appendListNode(list2, 83);
    appendListNode(list2, 45);
    appendListNode(list2, 27);
    appendListNode(list2, 91);
    appendListNode(list2, 76);
    appendListNode(list2, 62);

    printf("Original List:\n");
    displayList(list2);
    SelectionListDescendingRec(list2->head);
    printf("Selection sort sorted List:\n");
    displayList(list2);

    /* Free memory allocated for the second linked list */
    freeLinkedList(list2);

    return 0;
}

LinkedList* InsertionListDescendingIter(const LinkedList* head) {
    LinkedList* sortedList = createLinkedList();
    if (!sortedList) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    ListNode* current = head->head;

    while (current != NULL) {
        ListNode* newNode = createNode(current->value);
        if (!newNode) {
            printf("Memory allocation failed.\n");
            freeLinkedList(sortedList);
            return NULL;
        }

        ListNode* temp = sortedList->head;
        ListNode* prev = NULL;

        while (temp != NULL && temp->value > newNode->value) {
            prev = temp;
            temp = temp->next;
        }

        if (!prev) {
            newNode->next = sortedList->head;
            sortedList->head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = temp;
        }

        current = current->next;
    }

    return sortedList;
}

void SelectionListDescendingRec(ListNode* current) {
    if (current == NULL)
        return;

    ListNode* maxNode = findMax(current, current);
    swapValues(current, maxNode);

    SelectionListDescendingRec(current->next);
}

void swapValues(ListNode* node1, ListNode* node2) {
    double temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

ListNode* findMax(ListNode* start, ListNode* maxNode) {
    if (start == NULL) {
        return maxNode;
    }

    if (start->value > maxNode->value) {
        maxNode = start;
    }

    return findMax(start->next, maxNode);
}

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
    }
    return list;
}

void freeLinkedList(LinkedList* list) {
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

ListNode* createNode(double val) {
    ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
    if (newListNode != NULL) {
        newListNode->value = val;
        newListNode->next = NULL;
    }
    return newListNode;
}

void displayList(const LinkedList* list) {
    const ListNode* current = list->head;
    while (current != NULL) {
        printf("%lf ", current->value);
        current = current->next;
    }
    printf("\n");
}

void appendListNode(LinkedList* list, double val) {
    ListNode* newListNode = createNode(val);
    if (newListNode) {
        if (list->head == NULL) {
            list->head = newListNode;
            return;
        }

        ListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newListNode;
    } else {
        printf("Memory allocation failed.\n");
    }
}