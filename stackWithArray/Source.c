// Adding libraries.
#include<stdio.h>
#include<stdlib.h>

// Stack identification.
struct stack {
	unsigned capacity;	// Maximum number of elements.
	int top;			// Last value marker.
	int* array;			// Value repository.
};

// Creating stack and assing capacity.
struct stack* createStack(unsigned capacity) {
	struct stack* createdStack = (struct stack*)malloc(sizeof(struct stack));
	createdStack->top = -1;				// This element refers to the index of the array. Adding and removing operations change the values of this item.
	createdStack->capacity = capacity;	// Sets stack capacity.
	createdStack->array = (int*)malloc(sizeof(int) * capacity);	// Sets array usage for stack.
	return createdStack;
}

// Printing stack values.
void printStack(struct stack* root) {
	if (isEmpty(root) == 1)
		return;
	while (root->top != -1) {					// This loop go until to the stack end.
		printf("%d\t", root->array[root->top]);	// Prints the value in the array with the help of the top element.
		root->top--;							// Decrease top value.
	}
}

// Checks the fullness of the stack.
int isEmpty(struct stack* root) {
	return root->top == -1;					//If the stack is empty returned 1 value.
}

// Checks the fullness of the stack.
int isFull(struct stack* root) {
	return root->top == root->capacity - 1;	// If the stack is full returned 1 value.
}

// Adding new value in the stack.
void push(struct stack* root, int data) {
	if (isFull(root) == 1)							// This condition works if method returns 1 value.
		return -1;
	root->top++;									// Increase top value.
	root->array[root->top] = data;					// Sets value of the empty element in the array.
}

// Get element from stack.
int pop(struct stack* root) {
	if(isEmpty(root) == 1)							// This condition works if method returns 1 value.
		return -1;
	int valueToReturned = root->array[root->top];	// This valueToReturned elements takes the added last elements value in the stack.
	root->top--;									// Decrease top value.
	return valueToReturned;
}

// Finds the greatest element.
int findTheMaxValue(struct stack* root) {
	int maxValue = root->array[root->top--];		// This element takes the added last elements value in the stack.
	while (root->top != -1) {
		int data = root->array[root->top];
		if (data > maxValue)						// This condition works if next item is greater than start items and maxValue is changed.
			maxValue = data;						// Set maxValue.
		root->top--;
	}
	return maxValue;
}

int main() {
	// LIFO -> Last In First Out
	struct stack* mainStack = createStack(5);
	push(mainStack, 10);	// 10
	push(mainStack, 20);	// 20 10	
	push(mainStack, 30);	// 30 20 10
	push(mainStack, 40);	// 40 30 20 10
	pop(mainStack);			// 30 20 10
	printStack(mainStack);
	printf("%d", findTheMaxValue(mainStack));	// If this method isn't work close all printStack methods.
	return 0;
}
