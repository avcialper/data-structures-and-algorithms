#include<stdio.h>
#include<stdlib.h>
#include<string.h>	// For use string libraries.

struct stack {
	unsigned capacity;
	int top;
	int* array;
};

struct stack* createStack(unsigned capacity) {
	struct stack* createdStack = (struct stack*)malloc(sizeof(struct stack));
	createdStack->capacity = capacity;
	createdStack->top = -1;
	createdStack->array = (int*)malloc(sizeof(int) * capacity);
	return createdStack;
}

int isEmpty(struct stack* root) {
	return root->top == -1;
}

int isFull(struct stack* root) {
	return root->top == root->capacity - 1;
}

void push(struct stack* root, int data) {
	if (isFull(root) == 1)
		return;
	root->array[++root->top] = data;
}

int pop(struct stack* root) {
	if (isEmpty(root) == 1)
		return;
	return root->array[root->top--];
}

// Reversing an array.
void reverse(char txt[]) {						// This method want a char array.
	int length = strlen(txt);					// Find string length.
	struct stack* root = createStack(length);	// Created stack at the length of the array.
	for (int i = 0; i < length; i++)
		push(root, txt[i]);						// Stack use for reversing string value
	for (int i = 0; i < length; i++)
		txt[i] = pop(root);						// Adding value to array.
	printf("%s", txt);
}

int main() {

	char txt[] = "Word to be reversed.";		// .desrever eb ot droW
	reverse(txt);
	return 0;
}