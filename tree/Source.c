// Adding libraries.
#include<stdlib.h>
#include<stdio.h>

// Tree identification.
struct tree {
	int data;						// Value of the leave.
	struct tree* left;				// Go to left leave.
	struct tree* right;				// Go to right leave.
};

// Creating tree and assign value.
struct tree* createTree(int data) {
	struct tree* createdTree = (struct tree*)malloc(sizeof(struct tree));
	createdTree->data = data;		// Set value.
	createdTree->left = NULL;		// NULL is added to mark the left of the node.
	createdTree->right = NULL;		// NULL is added to mark the right of the node.
	return createdTree;
}

// Print left-head-right
void inorder(struct tree* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

// Print head-left-right
void preorder(struct tree* root) {
	if (root == NULL)
		return;
	printf("%d\t", root->data);
	preorder(root->left);
	preorder(root->right);
}

// Print left-right-head
void postorder(struct tree* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t", root->data);
}

// Add new leave of Binary Search Tree.
struct tree* insert(struct tree* root, int data) {
	if (root == NULL)
		return createTree(data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	else if (root->data > data)
		root->left = insert(root->left, data);
	return root;
}

// Finds the wanted value in the Binary Search Tree.
struct tree* search(struct tree* root, int wanted) {
	if (root == NULL)
		return NULL;
	else if (root->data == wanted)
		return root;
	else if (root->data > wanted)
		return search(root->left, wanted);
	else if (root->data < wanted)
		return search(root->right, wanted);
}

// Delete all items except head of the tree.
struct tree* deleteLeaves(struct tree* root) {
	if (root == NULL)
		return NULL;
	else if (root->right == NULL && root->left == NULL) {
		free(root);
		return;
	}
	root->left = deleteLeaves(root->left);
	root->right = deleteLeaves(root->right);
	return;
}

// Find the number of inner nodes.
int innerNodes(struct tree* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	int leftNodes = innerNodes(root->left);
	int rightNodes = innerNodes(root->right);
	return leftNodes + rightNodes + 1;
}

// Number of all elements of the tree.
static int count = 0;
int countNodes(struct tree* root) {
	if (root != NULL) {
		countNodes(root->left);
		count++;
		countNodes(root->right);
	}
}

// Find tree heaight.
int findTreeHeight(struct tree* root) {
	if (root == NULL)
		return -1;
	int leftHeight = findTreeHeight(root->left);
	int rightHeight = findTreeHeight(root->right);
	return findMax(leftHeight, rightHeight) + 1;
}

int findMax(int value1, int value2) {
	if (value1 > value2)
		return value1;
	return value2;
}

// Find max value.
int findMaxValue(struct tree* root) {
	if (root == NULL)
		return 0;
	int maxValue = root->data;
	int leftValue = findMaxValue(root->left);
	int rightValue = findMaxValue(root->right);
	if (leftValue > maxValue)
		maxValue = leftValue;
	if (rightValue > maxValue)
		maxValue = rightValue;
	return maxValue;
}

// Delete all items in the tree.
void deleteTree(struct tree* root) {
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int main() {

	struct tree* root = createTree(8);
	root->left = createTree(5);
	root->left->left = createTree(3);
	root->left->right = createTree(7);
	root->right = createTree(13);
	root->right->left = createTree(11);
	root->right->right = createTree(15);


	inorder(root);			// 3 5 7 8 11 13 15
	preorder(root);			// 8 5 3 7 13 11 15
	postorder(root);		// 3 7 5 11 15 13 8
	insert(root, 9);
	search(root, 11);
	deleteLeaves(root);
	int innerNodeValue = innerNodes(root);	// 2
	int countNodeValue = countNodes(root);	// 7
	int treeHeight = findTreeHeight(root);	// 2
	int maxItem = findMaxValue(root);		// 15
	deleteTree(root);
	return 0;
}