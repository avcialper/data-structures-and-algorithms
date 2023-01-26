// Adding libraries.
#include<stdio.h>
#include<stdlib.h>

// Node identification.
struct node {
	int data;				// Value of the node.
	struct node* next;		// Go to next node.
	struct node* prev;		// Go to previous node.
};

// Creating node and assing value.
struct node* createNode(int data) {
	struct node* createdNode = (struct node*)malloc(sizeof(struct node));
	createdNode->data = data;	// Set value.
	createdNode->next = NULL;	// NULL is added to mark the first and last node.
	createdNode->prev = NULL;
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
	nodeToAdd->next = (*head);					// Setting the node to the beginning of the list.
	(*head) = nodeToAdd;						// Changing the head position.
}

// Remove the first node in the list.
void deleteTheFistNode(struct node** head) {	// We will change the head position so we use double star.
	struct node* tmp = (*head);					// Creating the pointer to follow node.	This pointer point the first node in the list.
	(*head) = tmp->next;						// Changing the head position.
	free(tmp);									// Deleting the firts node in the list.
	(*head)->prev = NULL;						// Marked the first node.
}

// Add a node to the desired location.
void insertion(struct node* head, int data, int search) {	// Insertion will occur after the searched value.
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->data != search)					// This loop go until to the searched value.
		tmp = tmp->next;
	nodeToAdd->next = tmp->next;				// Node connected at the next of searched node.
	nodeToAdd->next->prev = nodeToAdd;			// Double connected of the two node is complete.
	tmp->next = nodeToAdd;						// Searched node is connected to nodeToAdd node.
	nodeToAdd->prev = tmp;						// Double connected of the two node is complete.
}

// Remove the searched node in the list.
void deleteTheSearchedNode(struct node* head, int search) {
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	while (tmp->next->data != search)			// This loop go to the previous of the searched value.
		tmp = tmp->next;
	struct node* nodeToDelete = tmp->next;		// This node is point the searched value.
	tmp->next = tmp->next->next;				// The tmp node is conneted the next of searched value.
	tmp->next->next->prev = tmp;				// Double connected of the two node is complete.
	free(nodeToDelete);							// Delete searched node.
}

// Add a node of the list end.
void append(struct node* head, int data) {
	struct node* tmp = head;					// Creating the pointer to follow node.	This pointer point the first node in the list.
	struct node* nodeToAdd = createNode(data);	// Creating of the node to add.
	while (tmp->next != NULL)					// This loop go to until of the list end.
		tmp = tmp->next;
	tmp->next = nodeToAdd;						// The nodeToAdd is connected the next of the tmp node.
	nodeToAdd->prev = tmp;						// Double connected of the two node is complete.
}

// Remove the last node in the list.
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
	node1->next = node2; node2->next = node3; node3->next = node4;
	node4->prev = node3; node3->prev = node2; node2->prev = node1;
	// NULL <- 10 <=> 20 <=> 30 <=> 40 -> NULL
	prepend(&node1, 0);			// This method wants pointer so we use the ampersand to send address. NULL <- 0 <=> 10 <=> 20 <=> 30 <=> 40 -> NULL
	deleteTheFistNode(&node1);	// This method wants pointer so we use the ampersand to send address. NULL <- 10 <=> 20 <=> 30 <=> 40 -> NULL
	insertion(node1, 35, 30);	// NULL <- 10 <=> 20 <=> 30 <=> 35 <=> 40 -> NULL
	deleteTheSearchedNode(node1, 35);	// NULL <- 10 <=> 20 <=> 30 <=> 40 -> NULL
	append(node1, 55);			// NULL <- 10 <=> 20 <=> 30 <=> 40 <=> 55 -> NULL
	deleteTheLastNode(node1);	// NULL <- 10 <=> 20 <=> 30 <=> 40 -> NULL
	printList(node1);
	return 0;
}