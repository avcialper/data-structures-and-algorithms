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

## linkedList content
- Node creation. ( createNode )
- Print list values. ( printList )
- Add a node to the beginning of the list. ( prepend )
- Remove the first node in the list. ( deleteTheFirstNode )
- Add a node to the desired location. ( insertion )
- Remove the searched node in the list. ( deleteTheSelectionNode )
- Add a node of the list end. ( append )
- Remove the last node in the list. ( deleteTheLastNode )