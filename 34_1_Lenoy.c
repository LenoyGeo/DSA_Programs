//To check if number is Fibonacci
#include <stdio.h>

// Function to check if a number is a perfect square
int isPerfectSquare(int num) {
    int sqrtNum = 0;
    while (sqrtNum * sqrtNum <= num) {
        if (sqrtNum * sqrtNum == num) {
            return 1; // It's a perfect square
        }
        sqrtNum++;
    }
    return 0; // It's not a perfect square
}

// Function to check if a number is a Fibonacci number
int isFibonacci(int num) {
    // A number is a Fibonacci number if either (5*num*num + 4) or (5*num*num - 4) is a perfect square
    return isPerfectSquare(5 * num * num + 4) || isPerfectSquare(5 * num * num - 4);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isFibonacci(num)) {
        printf("%d is a Fibonacci number.\n", num);
    } else {
        printf("%d is not a Fibonacci number.\n", num);
    }

    return 0;
}