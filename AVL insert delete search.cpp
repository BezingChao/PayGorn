#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Define AVL Tree node
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
 int height;
};
// Get the height of the node
int height(struct Node* node) {
 if(node == NULL)
 return 0;
 return node->height;
}
// Get the maximum of two integers
int max(int a, int b) {
 return (a > b) ? a : b;
}
// Create a new node
struct Node* createNode(int data) {
 struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 node->data = data;
 node->left = node->right = NULL;
 node->height = 1;
 return node;
}
// Right rotate subtree rooted with y
struct Node* rightRotate(struct Node* y) {
 struct Node* x = y->left;
 struct Node* T2 = x->right;
 x->right = y;
 y->left = T2;
 y->height = max(height(y->left), height(y->right)) + 1;
 x->height = max(height(x->left), height(x->right)) + 1;
 return x;
}
// Left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x) {
 struct Node* y = x->right;
 struct Node* T2 = y->left;
 y->left = x;
 x->right = T2;
 x->height = max(height(x->left), height(x->right)) + 1;
 y->height = max(height(y->left), height(y->right)) + 1;
 return y;
}
// Get balance factor
int getBalance(struct Node* node) {
 if(node == NULL)
 return 0;
 return height(node->left) - height(node->right);
}
// Insert node into AVL tree
struct Node* insert(struct Node* node, int data) {
 if(node == NULL)
 return createNode(data):
 if(data < node->data)
 node->left = insert(node->left, data);
 else if(data > node->data)
 node->right = insert(node->right, data);
 else
 return node; // Duplicate keys not allowed;
 node->height = 1 + max(height(node->left), height(node->right));
 int balance = getBalance(node);
 // Left Left Case
 if(balance > 1 && data < node->left->data)
 return rightRotate(node);
 // Right Right Case
 if(balance < -1 && data > node->right->data)
 return leftRotate(node);
 // Left Right Case
 if(balance > 1 && data > node->left->data) {
 node->left = leftRotate(node->left);
 return rightRotate(node);
 }
 // Right Left Case
 if(balance < -1 && data < node->right->data) {
 node->right = rightRotate(node->right);
 return leftRotate(node);
 }
 return node;
}
// Find minimum node in tree
struct Node* minValueNode(struct Node* node) {
 struct Node* current = node;
 while(current->left != NULL)
 current = current->left;
 return current;
}
// Delete node from AVL tree
struct Node* deleteNode(struct Node* root, int data) {
 if(root == NULL)
 return root;
 if(data < root->data)
 root->left = deleteNode(root->left, data);
 else if(data > root->data)
 root->right = deleteNode(root->right, data);
 else {
 if(root->left == NULL || root->right == NULL) {
 struct Node* temp = root->left ? root->left : root->right;
 if(temp == NULL) {
 temp = root;
 root = NULL;
 } else {
 *root = *temp;
 }
 free(temp);
 } else {
 struct Node* temp = minValueNode(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 }
 if(root == NULL)
 return root;
 root->height = 1 + max(height(root->left), height(root->right));
 int balance = getBalance(root);
 // Left Left Case
 if(balance > 1 && getBalance(root->left) >= 0)
 return rightRotate(root);
 // Left Right Case
 if(balance > 1 && getBalance(root->left) < 0) {
 root->left = leftRotate(root->left);
 return rightRotate(root);
 }
 // Right Right Case
 if(balance < -1 && getBalance(root->right) <= 0)
 return leftRotate(root);
 // Right Left Case
 if(balance < -1 && getBalance(root->right) > 0) {
 root->right = rightRotate(root->right);
 return leftRotate(root);
 }
 return root;
}
// Search for a node in AVL tree
struct Node* search(struct Node* root, int key) {
 if(root == NULL || root->data == key)
 return root;
 if(key < root->data)
 return search(root->left, key);
 else
 return search(root->right, key);
}
// Inorder traversal
void inorder(struct Node* root) {
 if(root != NULL) {
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
//Main function
void main() {
 struct Node* root = NULL;
 int choice, data;
 clrscr();
 while(1) {
 printf("\n--- AVL Tree Operations ---\n");
 printf("1. Insert\n2. Delete\n3. Search\n4. Display (Inorder)\n5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice):
 switch(choice) {
 case 1:
 printf("Enter element to insert: ");
 scanf("%d", &data);
 root = insert(root, data);
 printf("%d inserted.\n", data);
 break;
 case 2:
 printf("Enter element to delete: ");
 scanf("%d", &data);
 root = deleteNode(root, data);
 printf("%d deleted if present.\n", data);
 break;
 case 3:
 printf("Enter element to search: ");
 scanf("%d", &data);
 if(search(root, data) != NULL)
 printf("%d found in the AVL Tree.\n", data);
 else
 printf("%d not found in the AVL Tree.\n", data);
 break;
 case 4:
 printf("AVL Tree (Inorder): ");
 inorder(root);
 printf("\n");
 break;
 case 5:
 exit(0);
 default:
 printf("Invalid choice. Try again.\n");
 }
 }
 getch();
}