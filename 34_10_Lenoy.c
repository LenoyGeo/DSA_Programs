//Printing Unique Elements in Array
#include <stdio.h>

int isUnique(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

void printUniqueElements(int arr[], int size) {
    printf("Unique elements in the array are: ");
    for (int i = 0; i < size; i++) {
        if (isUnique(arr, i, arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printUniqueElements(arr, size);

    return 0;
}