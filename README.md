 # Data Structers And Algorithms
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

// Inside of main method.
printList(myNode);          // Before the adding.
prepend(&myNode, value);    // Adding.
printList(myNode);          // After the adding.
```

## linkedList & doubleLinkedList & circularLinkedList
- Node creation. ( createNode )
- Print list values. ( printList )
- Add a node to the beginning of the list. ( prepend )
- Remove the first node in the list. ( deleteTheFirstNode )
- Add a node to the desired location. ( insertion )
- Remove the searched node in the list. ( deleteTheSelectionNode )
- Add a node of the list end. ( append )
- Remove the last node in the list. ( deleteTheLastNode )
- (Only for circularLinkedList) Scroll the selected value at wanted number of steps. ( scrollOfValue )

## stackWithLinkedList & stackWithArray
- Node creation. ( createNode )
- Printing stack values. ( printStack )
- Checking stack elements. ( isEmpty )
- Adding new value in the stack. ( push )
- Remove element from stack. ( pop )
- Finds the greatest element. ( findTheMaxValue )

## factorialAndFibonacci
These methods use stack structures. In this file there are only explanations of fibonacci and factorial codes. Other method descriptions are in the stackWithArray file. <br/>
Fibonacci steps:
```
        top stack        value1          value2          print           the last stack
1-        1 - 0            1                0              0                 1 - 1
2-        1 - 1            1                1              1                 2 - 1
3-        2 - 1            2                1              1                 3 - 2
4-        3 - 2            3                2              2                 5 - 3
5-        5 - 3            5                3              3                 8 - 5
```

## reverseAString
These methods use stack structures. In this file there are only explanations of reverse codes. Other method descriptions are in the stackWithArray file.

## postfix
These methods use stack structures. In this file there are only explanations of postfix (evPost) codes. Other method descriptions are in the stackWithArray file. <br/> 59-4+87++ postfix steps.
```
1-      push 5                          5
2-      push 9                          9 5
3-      - operator                      value1 = 9      value2 = 5      5 - 9 = -4
        push -4                         -4
4-      push 4                          4 -4
5-      + operator                      value1 = 4      value2 = -4     -4 + 4 = 0
        push 0                          0
6-      push 8                          8 0
7-      push 7                          7 8 0
8-      + operator                      value1 = 7      value2 = 8      8 + 7 = 15
        push 15                         15 0
9-      + operator                      value1 = 15      value2 = 0     15 + 0 = 15
        push 15                         15
END     return 15
```