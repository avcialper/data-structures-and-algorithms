// Adding libraries.
#include<stdlib.h>
#include<stdio.h>

// Node identification.
struct node {
	int data;
	struct node* next;
};

// Creating node and assing value.
struct node* createNode(int data) {
	struct node* createdStack = (struct node*)malloc(sizeof(struct node));
	createdStack->data = data;		// Set value.
	createdStack->next = NULL;		// NULL is added to mark the last node.
	return createdStack;
}

// Printing stack values.
void printStack(struct node* head) {
	struct node* tmp = head;			// Creating the pointer to follow node. This pointer point the added last element in the stack.
	while (tmp != NULL) {				// This loop go until to the stack end.
		printf("%d\t", tmp->data);		// Printing the value of the stack.
		tmp = tmp->next;				// Set the pointer to the next node.
	}
}

// Checking stack elements.
int isEmpty(struct node* head){
	return head == NULL;				// If the stack is empty returned 1 value.
}

// Adding new value in the stack.
void push(struct node** head, int data) {		// We will change the head position so we use double star.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	nodeToAdd->next = (*head);					// Setts the node to the beginning of the stack.
	(*head) = nodeToAdd;						// Changing the head position.
}

// Remove element from stack.
int pop(struct node** head) {			// We will change the head position so we use double star.
	struct node* tmp = (*head);			// Creating the pointer to follow node. This pointer point the added last element in the stack.
	if (isEmpty(tmp) == 1)				// This condition works if method returns 1 value.
		return -1;
	int data = tmp->data;				// This data elements takes the added last elements value in the stack.
	(*head) = tmp->next;				// Changing the head position.
	free(tmp);							// Deleting the added last element in the satck.
	return data;						// Return the received value.
}

int findTheMaxValue(struct node* head) {
	struct node* tmp = head;			// Creating the pointer to follow node. This pointer point the added last element in the stack.
	int maxValue = tmp->data;			// This element takes the added last elements value in the stack.
	tmp = tmp->next;					// Set the pointer to the next node.
	while (tmp != NULL) {
		if (tmp->data > maxValue)		// This condition works if next item is greater than start items and maxValue is changed
			maxValue = tmp->data;
		tmp = tmp->next;
	}
	return maxValue;
}

int main() {
	// LIFO -> Last In First Out
	struct node* mainNode = createNode(10);	// 10
	push(&mainNode, 20);					// 20 10
	push(&mainNode, 30);					// 30 20 10
	push(&mainNode, 40);					// 40 30 20 10
	pop(&mainNode);							// 30 20 10
	printStack(mainNode);
	printf("%d",findTheMaxValue(mainNode));
	return 0;
}