#include <stdio.h>
#include<conio.h>
void bubbleSort(int arr[], int n) {
 for(int i = 0; i < n-1; i++) {
 for(int j = 0; j < n-i-1; j++) {
 if(arr[j] > arr[j+1]) {
 // Swap
 int temp = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = temp;
 }
 }
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
 printf("Enter number of elements for Bubble Sort: ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter elements:\n");
 for(int i = 0; i < n; i++)
 scanf("%d", &arr[i]);
 bubbleSort(arr, n);
 printf("Sorted array using Bubble Sort:\n");
 printArray(arr, n);
 getch();
}
