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
	do {							// The tmp pointer point the first node in the list, and we want print all node.
		printf("%d\t", tmp->data);	// Printing the value of the node.
		tmp = tmp->next;			// Set the pointer to the next node.
	} while (tmp != head);			// If the list head is found, this loop stops.
}

// Add a node to the beginning of the list.
void prepend(struct node** head, int data) {	// We will change the head position so we use double star.
	struct node* tmp = (*head);					// Creating the pointer to follow node.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->next != (*head))				// This loop go until to the list end. 
		tmp = tmp->next;
	nodeToAdd->next = (*head);					// Setts the node to the beginning of the list.
	tmp->next = nodeToAdd;						// Setts the node to the ending of the list.
	(*head) = nodeToAdd;						// Changes the head position.
}

// Remove the first node in the list.
void deleteTheFirstNode(struct node** head) {	// We will change the head position so we use double star.
	struct node* tmp = (*head);					// Creating the pointer to follow node.
	while (tmp->next != (*head))				// This loop go until to the list end.
		tmp = tmp->next;
	struct node* nodeToDelete = tmp->next;		// Point the node to deleted.
	tmp->next = tmp->next->next;				// The new first and last node in the list are connected.
	(*head) = tmp->next;						// Changes the head position.
	free(nodeToDelete);							// Deletes the first node in the list.
}

// Add a node to the desired location.
void insertion(struct node* head, int data, int search) {	// Insertion will occur after the searched value.
	struct node* tmp = head;					// Creating the pointer to follow node.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->data != search)					// This loop go until to the searched value.
		tmp = tmp->next;
	nodeToAdd->next = tmp->next;				// Node is added to the searched location. And the added node is connected to the next node from the tmp pointer next.
	tmp->next = nodeToAdd;						// The tmp pointer is connected to the added node.
}

// Remove the searced node in the list.
void deleteTheSearchedNode(struct node* head, int searched) {
	struct node* tmp = head;					// Creating the pointer to follow node.
	while (tmp->next->data != searched)			// This loop go to the previous of the searched value.
		tmp = tmp->next;
	struct node* nodeToDelete = tmp->next;		// Point the node to deleted.
	tmp->next = tmp->next->next;				// Connects the previous and next nodes of the searched node.
	free(nodeToDelete);							// Deletes the searched node.
}

// Add a node of the list.
void append(struct node* head, int data) {
	struct node* tmp = head;					// Creating the pointer to follow node.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->next != head)					// This loop go until to the list end.
		tmp = tmp->next;
	nodeToAdd->next = head;						// The nodeToAdd node is connected to the head node of the list.
	tmp->next = nodeToAdd;						// The tmp pointer is connected to the nodeToAdd node.
}

// Remove the last node in the list.
void deleteToLastNode(struct node* head) {
	struct node* tmp = head;					// Creating the pointer to follow node.
	while (tmp->next->next != head)				// This loop go to until the before of last node in the list.
		tmp = tmp->next;
	struct node* nodeToDelete = tmp->next;		// Point the node to deleted.
	tmp->next = head;							// Connects the new last node and head node of the list.
	free(nodeToDelete);							// Deletes the last node of the list.
}

// Scroll the selected value at wanted number of steps.
void scrollOfValue(struct node* head, int searched, int step) {
	struct node* tmp = head;					// Creating the pointer to follow node.
	int nodeToScroll;							// This parameter is include second scroll value.
	while (tmp->data != searched)				// This loop go to until the searched value.
		tmp = tmp->next;
	for (int i = 0; i < step; i++) {			// Loop run as many steps.
		nodeToScroll = tmp->next->data;			// Parameter takes the value of the node after the tmp node.
		tmp->next->data = searched;				// The node after the tmp node gets the value of the tmp node.
		tmp->data = nodeToScroll;				// Tmp node takes the value of the nodeToScroll.
		tmp = tmp->next;						// Set the pointer to the next node.
	}
}

int main() {
	
	struct node* node1 = createNode(10);
	struct node* node2 = createNode(20);
	struct node* node3 = createNode(30);
	struct node* node4 = createNode(40);
	node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node1;
	// 10 -> 20 -> 30 -> 40 -> 10 -> 20 .....  The first and last node in the list are connected.
	prepend(&node1, 0);					// This method wants pointer so we use the ampersand to send address. 0 -> 10 -> 20 -> 30 -> 40 -> 0 -> 10 -> 20 ...
	deleteTheFirstNode(&node1);			// This method wants pointer so we use the ampersand to send address. 10 -> 20 -> 30 -> 40 -> 10 -> 20 ...
	insertion(node1, 35, 30);			// 10 -> 20 -> 30 -> 35 -> 40 -> 10 -> 20 ...
	deleteTheSearchedNode(node1, 35);	// 10 -> 20 -> 30 -> 40 -> 10 -> 20 ...
	append(node1, 55);					// 10 -> 20 -> 30 -> 40 -> 55 -> 10 -> 20 ...
	deleteToLastNode(node1);			// 10 -> 20 -> 30 -> 40 -> 10 -> 20 ...
	scrollOfValue(node1, 20, 2);		// 10 -> 30 -> 40 -> 20 -> 10 -> 30 ...
	printList(node1);
	return 0;
}