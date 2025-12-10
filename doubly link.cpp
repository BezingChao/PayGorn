#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *prev, *next;
};
struct Node* createNode(int value) {
 struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}
void insertEnd(struct Node **head, int value) {
 struct Node *newNode = createNode(value);
 if (*head == NULL) {
 *head = newNode;
 return;
 }
 struct Node *temp = *head;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = newNode;
 newNode->prev = temp;
}
void deleteNode(struct Node **head, int value) {
 struct Node *temp = *head;
 while (temp != NULL && temp->data != value)
 temp = temp->next;
 if (temp == NULL) {
 printf("Value not found\n");
 return;
 }
 if (temp->prev != NULL)
 temp->prev->next = temp->next;
 else
 *head = temp->next;
 if (temp->next != NULL)
 temp->next->prev = temp->prev;
 free(temp);
}
void traverse(struct Node *head) {
 struct Node *temp = head;
 printf("List: ");
 while (temp != NULL) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}
int main() {
 struct Node *head = NULL;
 clrscr();
 insertEnd(&head, 10);
 insertEnd(&head, 20);
 insertEnd(&head, 30);
 printf("After insertion:\n");
 traverse(head);
 deleteNode(&head, 20);
 printf("After deletion of 20:\n");
 traverse(head);
 getch();
 return 0;
}