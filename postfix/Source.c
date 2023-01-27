#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>		// For use type libraries.

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

int isFull(struct stack* root) {
	return root->top == root->capacity - 1;
}

int isEmpty(struct stack* root) {
	return root->top == -1;
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

// Calculates the postfix.
int evPost(char* postfix) {		// This method want a char array.
	int length = strlen(postfix);
	struct stack* postfixStack = createStack(length);	// Created stack at the length of the array.
	for (int i = 0; i < length; i++) {
		if (isdigit(postfix[i]))	// Check the value is number or char. If the value is number this work the condition.
			push(postfixStack, postfix[i] - 48);	// This array is char array.
													// Since the value type is character, its number equivalent in ASCII is 48 less.
		else {
			int value1 = pop(postfixStack);			// Receiving the two values to be processed.
			int value2 = pop(postfixStack);
			switch (postfix[i]) {					// Transaction type control.
				case '+':
					push(postfixStack, value2 + value1);
					break;
				case '-':
					push(postfixStack, value2 - value1);
					break;
				case '*':
					push(postfixStack, value2 * value1);
					break;
				case '/':
					push(postfixStack, value2 / value1);
					break;
				case '%':
					push(postfixStack, value2 % value1);
					break;
			}
		}
	}
	return pop(postfixStack);
}

int main() {
	char postfix[] = "59-4+87++";
	printf("%d", evPost(postfix));		// 15
	return 0;
}
