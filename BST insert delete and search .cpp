#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Define the structure for BST node
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Create a new node
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}
// Insert a node in BST
struct Node* insert(struct Node* root, int data) {
 if(root == NULL) {
 return createNode(data);
 }
 if(data < root->data) {
 root->left = insert(root->left, data);
 } else if(data > root->data) {
 root->right = insert(root->right, data);
 }
 return root;
}
// Find the minimum node (used in delete)
struct Node* findMin(struct Node* root) {
 while(root->left != NULL)
 root = root->left;
 return root;
}
// Delete a node in BST
struct Node* deleteNode(struct Node* root, int data) {
 if(root == NULL)
 return root;
 if(data < root->data) {
 root->left = deleteNode(root->left, data);
 } else if(data > root->data) {
 root->right = deleteNode(root->right, data);
 } else {
 // Node found
 if(root->left == NULL) {
 struct Node* temp = root->right;
 free(root);
 return temp;
 } else if(root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 } else {
 struct Node* temp = findMin(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 }
 return root;
}
// Search for a node in BST
struct Node* search(struct Node* root, int key) {
 if(root == NULL || root->data == key)
 return root;
 if(key < root->data)
 return search(root->left, key);
 else
 return search(root->right, key);
}
// Inorder traversal to display the BST
void inorder(struct Node* root) {
 if(root != NULL) {
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
//Main Function
void main() {
 struct Node* root = NULL;
 int choice, data;
 clrscr();
 while(1) {
 printf("\n--- BST Operations ---\n");
 printf("1. Insert\n2. Delete\n3. Search\n4. Display (Inorder)\n5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
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
 printf("%d deleted if it was present.\n", data);
 break;
 case 3:
 printf("Enter element to search: ");
 scanf("%d", &data);
 if(search(root, data) != NULL)
 printf("%d found in the BST.\n", data);
 else
 printf("%d not found in the BST.\n", data);
 break;
 case 4:
 printf("BST (Inorder): ");
 inorder(root);
 printf("\n");
 break;
 case 5:
 exit(0);
 default:
 printf("Invalid choice. Try again.\n");
 }
 }
 Getch();
}
