#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAX 5
// Queue using Array
int queue[MAX];
int front = -1, rear = -1;
// Queue using Linked List
struct Node {
int data;
struct Node* next;
};
struct Node* frontNode = NULL;
struct Node* rearNode = NULL;
// Function prototypes
void enqueueArray(int value);
void dequeueArray();
void displayArray();
void enqueueLL(int value);
void dequeueLL();
void displayLL();
//Main Function
void main() {
printf("QUEUE IMPLEMENTATION USING ARRAY & LINKED LIST\n");
 clrscr();
// Array Queue demonstration
printf("\n*** ARRAY QUEUE ***\n");
enqueueArray(10);
enqueueArray(20);
enqueueArray(30);
displayArray();
dequeueArray();
displayArray();
// Linked List Queue demonstration
printf("\n*** LINKED LIST QUEUE ***\n");
enqueueLL(100);
enqueueLL(200);
enqueueLL(300);
displayLL();
dequeueLL();
displayLL();
getch();
}
// Array Queue Functions
void enqueueArray(int value) {
if (rear == MAX - 1) {
printf("Queue Overflow!\n");
} else {
if (front == -1)
front = 0;
rear++;
queue[rear] = value;
printf("Enqueued %d in Array Queue\n", value);
}
}
void dequeueArray() {
if (front == -1 || front > rear) {
printf("Queue Underflow!\n");
} else {
printf("Dequeued %d from Array Queue\n", queue[front]);
front++;
}
}
void displayArray() {
if (front == -1 || front > rear) {
printf("Queue is empty!\n");
} else {
printf("Queue elements in Array:\n");
for (int i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}
}
// Linked List Queue Functions
void enqueueLL(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (frontNode == NULL) {
frontNode = rearNode = newNode;
} else {
rearNode->next = newNode;
rearNode = newNode;
}
printf("Enqueued %d in Linked List Queue\n", value);
}
void dequeueLL() {
if (frontNode == NULL) {
printf("Queue Underflow!\n");
} else {
struct Node* temp = frontNode;
printf("Dequeued %d from Linked List Queue\n", frontNode->data);
frontNode = frontNode->next;
free(temp);
}
}
void displayLL() {
if (frontNode == NULL) {
printf("Queue is empty!\n");
} else {
printf("Queue elements in Linked List:\n");
struct Node* temp = frontNode;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}