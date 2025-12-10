#include <stdio.h>
#include<conio.h>
// Linear Search – Non Recursive
int linearSearch(int arr[], int n, int key) {
for (int i = 0; i < n; i++) {
if (arr[i] == key)
return i;
}
return -1;
}
// Linear Search – Recursive
int linearSearchRecursive(int arr[], int n, int index, int key) {
if (index >= n)
return -1;
if (arr[index] == key)
return index;
return linearSearchRecursive(arr, n, index + 1, key);
}
// Binary Search – Non Recursive
int binarySearch(int arr[], int n, int key) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = (low + high) / 2;
if (arr[mid] == key)
return mid;
else if (key < arr[mid])
high = mid - 1;
else
low = mid + 1;
}
return -1;
}
// Binary Search – Recursive
int binarySearchRecursive(int arr[], int low, int high, int key) {
if (low > high)
return -1;
int mid = (low + high) / 2;
if (arr[mid] == key)
return mid;
else if (key < arr[mid])
return binarySearchRecursive(arr, low, mid - 1, key);
else
return binarySearchRecursive(arr, mid + 1, high, key);
}
void main() {
int arr[] = {10, 20, 30, 40, 50};
int n = 5;
int key = 30;
 clrscr();
printf("LINEAR SEARCH\n");
printf("Non-recursive index: %d\n", linearSearch(arr, n, key));
printf("Recursive index: %d\n", linearSearchRecursive(arr, n, 0, key));
printf("\nBINARY SEARCH\n");
printf("Non-recursive index: %d\n", binarySearch(arr, n, key));
printf("Recursive index: %d\n", binarySearchRecursive(arr, 0, n - 1, key));
getch();
}
