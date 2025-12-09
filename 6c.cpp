#include <stdio.h>
#include <conio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
// Enqueue
void enqueue(int value) {
if ((rear + 1) % MAX == front) {
printf("Queue Overflow!\n");
} else {
if (front == -1)
front = 0;
rear = (rear + 1) % MAX;
queue[rear] = value;
printf("Enqueued %d\n", value);
}
}
// Dequeue
void dequeue() {
if (front == -1) {
printf("Queue Underflow!\n");
} else {
printf("Dequeued %d\n", queue[front]);
if (front == rear) {
front = rear = -1;
} else {
front = (front + 1) % MAX;
}
}
}
// Display
void display() {
if (front == -1) {
printf("Queue is empty!\n");
} else {
printf("Queue elements are:\n");
int i = front;
while (1) {
printf("%d ", queue[i]);
if (i == rear)
break;
i = (i + 1) % MAX;
}
printf("\n");
}
}
void main() {
clrscr();
printf("CIRCULAR QUEUE USING ARRAY\n");
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
display();
dequeue();
display();
enqueue(50);
enqueue(60); // This should show overflow if full
display();
getch();
}