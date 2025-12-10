#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAX 5
// Stack using Array
int stack[MAX];
int top = -1;
// Stack using Linked List
struct Node {
 int data;
 struct Node* next;
};
struct Node* topNode = NULL;
// Function Prototypes
void push(int value);
void pop();
void peek();
void display();
void pushLL(int value);
void popLL();
void peekLL();
void displayLL();
void demo2DArray();
void demoStrings();
//Main Function
void main() {
 int choice, value;
clrscr();
 printf("STACK IMPLEMENTATION USING ARRAY & LINKED LIST\n");
 // Array Stack demo
 printf("\n*** ARRAY STACK ***\n");
 push(10);
 push(20);
 push(30);
 display();
 pop();
 peek();
 display();
 // Linked List Stack demo
 printf("\n*** LINKED LIST STACK ***\n");
 pushLL(100);
 pushLL(200);
 pushLL(300);
 displayLL();
 popLL();
 peekLL();
 displayLL();
 // 2-D Array demo
 demo2DArray();
 // String demo
 demoStrings();
 getch();
}
// Array Stack Functions
void push(int value) {
 if (top == MAX - 1) {
 printf("Stack Overflow!\n");
 } else {
 top++;
 stack[top] = value;
 printf("Pushed %d\n", value);
 }
}
void pop() {
 if (top == -1) {
 printf("Stack Underflow!\n");
 } else {
 printf("Popped %d\n", stack[top]);
 top--;
 }
}
void peek() {
 if (top == -1) {
 printf("Stack is empty!\n");
 } else {
 printf("Top element is %d\n", stack[top]);
 }
}
void display() {
 if (top == -1) {
 printf("Stack is empty!\n");
 } else {
 printf("Stack elements are:\n");
 for (int i = top; i >= 0; i--) {
 printf("%d\n", stack[i]);
 }
 }
}
// Linked List Stack Functions
void pushLL(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->next = topNode;
 topNode = newNode;
 printf("Pushed %d in Linked List Stack\n", value);
}
void popLL() {
 if (topNode == NULL) {
 printf("Stack Underflow!\n");
 } else {
 struct Node* temp = topNode;
 printf("Popped %d from Linked List Stack\n", topNode->data);
 topNode = topNode->next;
 free(temp);
 }
}
void peekLL() {
 if (topNode == NULL) {
 printf("Stack is empty!\n");
 } else {
 printf("Top element is %d\n", topNode->data);
 }
}
void displayLL() {
 if (topNode == NULL) {
 printf("Stack is empty!\n");
 } else {
 printf("Stack elements are:\n");
 struct Node* temp = topNode;
 while (temp != NULL) {
 printf("%d\n", temp->data);
 temp = temp->next;
 }
 }
}
// 2-D Array demo
void demo2DArray() {
 int matrix[2][3] = {
 {1, 2, 3},
 {4, 5, 6}
 };
 printf("\n2-D Array elements:\n");
 for (int i = 0; i < 2; i++) {
 for (int j = 0; j < 3; j++) {
 printf("%d ", matrix[i][j]);
 }
 printf("\n");
 }
}
// Strings demo
void demoStrings() {
 char str[100];
 printf("\nEnter a string: ");
 scanf(" %[^\n]", str);
 printf("You entered: %s\n", str);
}