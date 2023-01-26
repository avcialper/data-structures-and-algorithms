// Adding libraries.
#include<stdlib.h>
#include<stdio.h>

// Node identification.
struct node {
	int data;						// Value of the node.
	struct node* next;				// Go to next node.
};

// Creating node and assing value.
struct node* createNode(int data) {
	struct node* createdNode = (struct node*)malloc(sizeof(struct node));
	createdNode->data = data;		// Set value.
	createdNode->next = NULL;		// NULL is added to mark the last node.
	return createdNode;
}

// Printing list values.
void printList(struct node* head) {
	struct node* tmp = head;		// Creating the pointer to follow node. This pointer point the first node in the list.
	while (tmp != NULL) {			// This loop go until to the list end. 
		printf("%d\t", tmp->data);	// Printing the value of the node.
		tmp = tmp->next;			// Set the pointer to the next node.
	}
}

// Add a node to the beginning of the list.
void prepend(struct node** head, int data) {	// We will change the head position so we use double star.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	nodeToAdd->next = (*head);					// Setts the node to the beginning of the list.
	(*head) = nodeToAdd;						// Changing the head position.
}

// Remove the first node in the list.
void deleteTheFirstNode(struct node** head) {	// We will change the head position so we use double star.
	struct node* tmp = (*head);					// Creating the pointer to follow node.	This pointer point the first node in the list.
	(*head) = tmp->next;						// Changing the head position.
	free(tmp);									// Deleting the firts node in the list.
}

// Add a node to the desired location.
void insertion(struct node* head, int data, int search) {	// Insertion will occur after the searched value.
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->data != search)					// This loop go until to the searched value.
		tmp = tmp->next;
	nodeToAdd->next = tmp->next;				// Node is added to the searched location. And the added node is connected to the next node from the tmp pointer next.
	tmp->next = nodeToAdd;						// The tmp pointer is connected to the added node.
}

// Remove the searched node in the list.
void deleteTheSeachedNode(struct node* head, int search) {
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	while (tmp->next->data != search)			// This loop go to the previous of the searched value.
		tmp = tmp->next;
	struct node* nodeToDeleted = tmp->next;		// This node point the searched value.
	tmp->next = tmp->next->next;				// Connected the nodes.
	free(nodeToDeleted);						// Deleting the searched node.
}


// Add a node of the list end.
void append(struct node* head, int data) {
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->next != NULL)					// This loop go to until of the list end.
		tmp = tmp->next;
	tmp->next = nodeToAdd;						// The tmp pointer is connected to the nodeToAdd node.
}

// Removing the last node in the list.
void deleteTheLastNode(struct node* head) {
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	while (tmp->next->next != NULL)				// This loop go to until the before at the list end.
		tmp = tmp->next;
	free(tmp->next);							// Deleting of the list end.
	tmp->next = NULL;							// Marked a end of the list.
}

int main() {
	struct node* node1 = createNode(10);
	struct node* node2 = createNode(20);
	struct node* node3 = createNode(30);
	struct node* node4 = createNode(40);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;				// 10 -> 20 -> 30 -> 40 -> NULL
	printList(node1);
	prepend(&node1, 0);					// This method wants pointer so we use the ampersand to send address. 0 -> 10 -> 20 -> 30 -> 40 -> NULL
	deleteTheFirstNode(&node1);			// This method wants pointer so we use the ampersand to send address. 10 -> 20 -> 30 -> 40 -> NULL
	insertion(node1, 25, 20);			// 10 -> 20 -> 25 -> 30 -> 40 -> NULL
	deleteTheSeachedNode(node1, 25);	// 10 -> 20 -> 30 -> 40 -> NULL
	append(node1, 50);					// 10 -> 20 -> 30 -> 40 -> 50 -> NULL
	deleteTheLastNode(node1);			// 10 -> 20 -> 30 -> 40 -> NULL
	return 0;
}
