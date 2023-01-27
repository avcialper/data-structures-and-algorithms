#include <stdio.h>
#include <stdlib.h>

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

// Find the factorial of the sent value.
void factorial(int data) {
	struct stack* root = createStack(data);
	while (data != 1)			// It goes until to one.
		push(root, data--);		// First the values in the data are pushed to the stack. Then the data values is decremented.
	int multiplicationResult = 1;
	while (root->top != -1)
		multiplicationResult *= pop(root);	// All number in the stack are multiplied.
	printf("Multiplication result = %d", multiplicationResult);
}

// Printing as many fibonacci steps as desired with stacks.
void fibonacci(int step) {
	struct stack* root = createStack(2);
	push(root, 0);
	push(root, 1);
	for (int i = 0; i < step; i++) {
		int value1 = pop(root);			// Value assignment.
		int value2 = pop(root);			// Value assignment.
		push(root, value1);
		push(root, value1 + value2);
		printf("%d\t", value2);
	}
}

int main() {

	factorial(5);		// 120
	printf("\n");
	fibonacci(4);		// 0 1 1 2
	return 0;
}