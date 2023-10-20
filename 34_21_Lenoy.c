/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 27.09.2023
Desription: Program to Implement Bubble or Selection Sort
*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    printf("Sorted Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[100], c, n, i;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    printf("Enter Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter 1 for Bubble Sort or 2 for Selection Sort: ");
    scanf("%d", &c);

    printf("Unsorted Order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    switch (c) {
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            selectionSort(a, n);
            break;
        default:
            printf("Invalid Number.\n");
            break;
    }

    return 0;
}


