#include<stdio.h>
#include<stdlib.h>

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

void printQueue(struct stack* root) {
	while (root->top != -1)
		printf("%d\t", root->array[root->top--]);
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

void enqueue(struct stack* root, int data) {
	if (isFull(root) == 1)		// This condition works if method returns 1 value.
		return;
	struct stack* secondStack = createStack(root->capacity);	// This stack contains the elements of the root stack.
	while (root->top != -1) {	// To empty the root stack.
		int item = pop(root);
		push(secondStack, item);
	}
	push(root, data);			// Add the element to the bottom of the root stack.
	while (secondStack->top != -1) {	// Root stack gets back all its items.
		int item = pop(secondStack);
		push(root, item);
	}
}

int dequeue(struct stack* root) {
	if (isEmpty(root) == 1)
		return;
	return root->array[root->top--];
}

int main() {
	struct stack* queue = createStack(5);
	enqueue(queue, 10);		// 10
	enqueue(queue, 20);		// 10 20
	enqueue(queue, 30);		// 10 20 30
	enqueue(queue, 40);		// 10 20 30 40
	enqueue(queue, 50);		// 10 20 30 40 50
	enqueue(queue, 60);		// 10 20 30 40 50		stack is full, 60 could not be added.
	dequeue(queue);			// 20 30 40 50
	enqueue(queue, 70);		// 20 30 40 50 70
	printQueue(queue);
	return 0;
}