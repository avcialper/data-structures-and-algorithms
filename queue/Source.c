// Adding libraries.
#include<stdio.h>
#include<stdlib.h>

// Queue identification.
struct queue {
	int rear;			// Marks the end of the queue.
	int front;			// Marks the head of the queue.
	int size;			// Keeps the number of elements.
	unsigned capacity;	// Maximum number of elements.
	int* array;			// Value repository.
};

// Creating queue and assing capacity.
struct queue* createQueue(unsigned capacity) {
	struct queue* createdQueue = (struct queue*)malloc(sizeof(struct queue));
	createdQueue->size = 0;		// Initially, the number of elements in the queue is zero.
	createdQueue->front = 0;	// This element refers to the index of the array. Adding operations change the values of this item.
	createdQueue->rear = -1;	// This element refers to the index of the array. Removing operations change the values of this item.
	createdQueue->capacity = capacity;	// Sets queue capacity.
	createdQueue->array = (int*)malloc(sizeof(int) * capacity);	// Sets array usage for queue.
	for (int i = 0; i < capacity; i++)
		createdQueue->array[i] = NULL;		// We made all the elements NULL to check.
	return createdQueue;
}

// Printing queue values.
void printQueue(struct queue* root) {
	for (int i = root->front; i < root->capacity; i++) {	// Initially, start front of the array and go to until end of the array.
		if (root->array[i] == NULL)				// If index of the array is empty, loop is broke.
			return;
		else									// Else, prints elements in the array.
			printf("%d\t", root->array[i]);
	}
	for (int i = 0; i < root->front; i++) {		// Then start from the beginning of the array and go to until the front.
		if (root->array[i] == NULL)				// If index of the array is empty, loop is broke.
			return;
		else									// Else, prints elements in the array.
			printf("%d\t", root->array[i]);
	}
}

// Checks the fullness of the stack.
int isEmpty(struct queue* root) {
	return root->size == 0;					//If the stack is empty returned 1 value.
}

// Checks the fullness of the stack.
int isFull(struct queue* root) {
	return root->size == root->capacity;	//If the stack is full returned 1 value.
}

// Adding new value in the queue.
void enqueue(struct queue* root, int data) {
	if (isFull(root) == 1)				// This condition works if method returns 1 value.
		return;
	root->rear++;						// Increase rear value.
	if (root->rear == root->capacity)   // If the rear element go to until the array end this condition is work.
		root->rear = 0;					// Rear element mark the first index.
	root->array[root->rear] = data;		// Sets value of the empty element in the array.
	root->size++;						// Increase size value.
}

// Remove element from queue.
int dequeue(struct queue* root) {
	if (isEmpty(root) == 1)					// This condition works if method returns 1 value.
		return;
	int data = root->array[root->front];	// Takes element in the queue.
	root->array[root->front] = NULL;		// We assigned NULL for check.
	root->front++;							// Increase front value.
	root->size--;							// Decrease size value.
}

int main() {
	struct queue* mainQueue = createQueue(5);
	enqueue(mainQueue, 10);		// 10
	enqueue(mainQueue, 20);		// 10 20
	enqueue(mainQueue, 30);		// 10 20 30
	enqueue(mainQueue, 40);		// 10 20 30 40
	dequeue(mainQueue);			// 20 30 40		Remove 10
	dequeue(mainQueue);			// 30 40		Remove 20
	enqueue(mainQueue, 50);		// 30 40 50
	enqueue(mainQueue, 100);	// 30 40 50 100
	enqueue(mainQueue, 200);	// 30 40 50 100 200
	enqueue(mainQueue, 300);	// 30 40 50 100 200  queue is full, 300 could not be added.
	printQueue(mainQueue);
	return 0;
}