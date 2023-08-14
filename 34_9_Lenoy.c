//Counting Duplicates in Array
#include <stdio.h>

int countDuplicateElements(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break; // Count each duplicate element only once
            }
        }
    }

    return count;
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

    int duplicateCount = countDuplicateElements(arr, size);

    printf("Total number of duplicate elements: %d\n", duplicateCount);

    return 0;
}