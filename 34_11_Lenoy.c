//Stack Operations Program
#include <stdio.h>

void push(int n); //inserts element
int pop(); //deletes last element
void show(); //show elements of array

int stack[10];
int top = -1;

int main() {
    int ch, n;
    while (1) {
        printf("\nOperations:");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Show Elements");
        printf("\n4. Exit");
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter Element to be Inserted:");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                if (top == -1) {
                    printf("\nStack is Empty. Cannot delete element.\n");
                } else {
                    int deletedValue = pop();
                    printf("\nDeleted Element: %d\n", deletedValue);
                }
                break;
            case 3:
                show();
                break;
            case 4:
                return 0; // Exit the program
            default:
                printf("\nInvalid Choice.\n");
        }
    }
}

void push(int n) {
    if (top == 9) {
        printf("\nStack is Full.");
    } else {
        top++;
        stack[top] = n;
    }
}

int pop() {
    int poppedValue = stack[top];
    top--;
    return poppedValue;
}

void show() {
    if (top == -1) {
        printf("\nStack is Empty.\n");
    } else {
        printf("\nElements are:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }       
}
