#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
 int data;
 struct Node *next;
};
struct Node *head = NULL; // Head pointer
// Function to create linked list with n nodes
void createList(int n) {
 struct Node *newNode, *temp;
 int data, i;
 if (n <= 0) {
 printf("\nInvalid number of nodes.");
 return;
 }
 head = (struct Node *)malloc(sizeof(struct Node));
 if (head == NULL) {
 printf("\nMemory not allocated!");
 return;
 }
 printf("Enter data for node 1: ");
 scanf("%d", &data);
 head->data = data;
 head->next = NULL;
 temp = head;
 for (i = 2; i <= n; i++) {
 newNode = (struct Node *)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("\nMemory not allocated!");
 break;
 }
 printf("Enter data for node %d: ", i);
 scanf("%d", &data);
 newNode->data = data;
 newNode->next = NULL;
 temp->next = newNode;
 temp = newNode;
 }
 printf("\nLinked list created successfully.\n");
}
// Function to insert at end
void insertNode(int value) {
 struct Node *newNode, *temp;
 newNode = (struct Node *)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("\nMemory not allocated!");
 return;
 }
 newNode->data = value;
 newNode->next = NULL;
 if (head == NULL) {
 head = newNode;
 } else {
 temp = head;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = newNode;
 }
 printf("\nNode inserted successfully.\n");
}
// Function to delete by value
void deleteNode(int value) {
 struct Node *temp = head, *prev = NULL;
 if (head == NULL) {
 printf("\nList is empty.");
 return;
 }
 // If head node holds the value
 if (temp != NULL && temp->data == value) {
 head = temp->next;
 free(temp);
 printf("\nNode with value %d deleted.\n", value);
 return;
 }
 // Search for the value
 while (temp != NULL && temp->data != value) {
 prev = temp;
 temp = temp->next;
 }
 // If not found
 if (temp == NULL) {
 printf("\nValue not found in list.");
 return;
 }
 prev->next = temp->next;
 free(temp);
 printf("\nNode with value %d deleted.\n", value);
}
// Function to display list
void displayList() {
 struct Node *temp = head;
 if (head == NULL) {
 printf("\nList is empty.");
 return;
 }
 printf("\nLinked List: ");
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
}
// Main function
void main() {
 int choice, n, value;
 clrscr();
 while (1) {
 printf("\n===== Singly Linked List Menu =====");
 printf("\n1. Create List");
 printf("\n2. Insert Node");
 printf("\n3. Delete Node");
 printf("\n4. Display List");
 printf("\n5. Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter number of nodes: ");
 scanf("%d", &n);
 createList(n);
 break;
 case 2:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 insertNode(value);
 break;
 case 3:
 printf("Enter value to delete: ");
 scanf("%d", &value);
 deleteNode(value);
 break;
 case 4:
 displayList();
 break;
 case 5:
 exit(0);
 default:
 printf("\nInvalid choice! Try again.");
 }
 }
 getch();
}
