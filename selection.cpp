#include <stdio.h>
#include<conio.h>
void selectionSort(int arr[], int n) {
 for(int i = 0; i < n-1; i++) {
 int minIndex = i;
 for(int j = i+1; j < n; j++) {
 if(arr[j] < arr[minIndex])
 minIndex = j;
 }
 // Swap
 int temp = arr[minIndex];
 arr[minIndex] = arr[i];
 arr[i] = temp;
 }
}
void printArray(int arr[], int n) {
 for(int i = 0; i < n; i++)
 printf("%d ", arr[i]);
 printf("\n");
}
//Main Function
void main() {
 int n;
clrscr();
 printf("Enter number of elements for Selection Sort: ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter elements:\n");
 for(int i = 0; i < n; i++)
 scanf("%d", &arr[i]);
 selectionSort(arr, n);
 printf("Sorted array using Selection Sort:\n");
 printArray(arr, n);
 getch();
}