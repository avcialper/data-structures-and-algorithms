 # data-structers-and-algorithms
If you want to test a method, choose a method and use it with print method created in the class. <br/>
For example in a linkedList structures
```c
// This method prints the values of the list.
void printList(struct node* head) {
        struct node* tmp = head;
        while (tmp != NULL) {
                printf("%d\t", tmp->data);
                tmp = tmp->next;
        }
}

// Add a node to the beginning of the list.
void prepend(struct node** head, int data) {
        struct node* nodeToAdd = createNode(data);
        nodeToAdd->next = (*head);
        (*head) = nodeToAdd;
}

printList(myNode);          // Before the adding.
prepend(&myNode, value);    // Adding.
printList(myNode);          // After the adding.
```