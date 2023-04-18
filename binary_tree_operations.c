

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct Node
{
	int data;
	struct Node* left, * right;
}Node;


Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Function to insert nodes in level order
Node* insertLevelOrder(int arr[],
					int i, int n)
{
	Node *root = NULL;

	if (i < n)
	{
		root = newNode(arr[i]);

		root->left = insertLevelOrder(arr,
				2 * i + 1, n);

		root->right = insertLevelOrder(arr,
				2 * i + 2, n);
	}
	return root;
}

// Function to print tree nodes in
// InOrder fashion
// void inOrder(Node* root)
// {
// 	if (root != NULL)
// 	{
// 		inOrder(root->left);
// 		printf("%d",root->data);
// 		inOrder(root->right);
// 	}
// }

// Helper function to print whitespace
void printSpace(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Recursive function to print a binary tree
void printBinaryTree(Node* root, int depth) {
    if (root == NULL) {
        return;
    }

    // Print the right subtree first
    printBinaryTree(root->right, depth + 1);

    // Print the current node
    printSpace(depth * 4);
    printf("%d\n", root->data);

    // Print the left subtree last
    printBinaryTree(root->left, depth + 1);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 12, 11, 34, 23 , 12 ,34};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node* root = insertLevelOrder(arr, 0, n);
	printBinaryTree(root,n);
}
