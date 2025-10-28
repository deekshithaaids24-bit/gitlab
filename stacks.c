#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 5
int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int element) {
    if (isFull()) {
        printf("\nSTACK Overflow! %d.\n", element);
    } else {
        stack[++top] = element;
        printf("\n%d pushed onto stack.\n", element);
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow!\n");
    } else {
        printf("\nPopped element: %d\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nStack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void checkPalindrome() {
    char str[50];
    int i, len, flag = 1;

    printf("\nEnter a string to check palindrome: ");
    scanf("%s", str);

    len = strlen(str);
    top = -1;

    for (i = 0; i < len; i++) {
        if (isFull()) {
            printf("\nStack Overflow while checking palindrome!\n");
            return;
        }
        stack[++top] = str[i];
    }

    for (i = 0; i < len; i++) {
        if (str[i] != stack[top--]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("\nThe string '%s' is a palindrome.\n", str);
    } else {
        printf("\nThe string '%s' is NOT a palindrome.\n", str);
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n......STACK OPERATIONS MENU......\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                pop();
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                printf("\nDemonstrating Overflow:\n");
                top = -1;
                for (int i = 1; i <= MAX + 1; i++) {
                    push(i * 10);
                }
                printf("\nDemonstrating Underflow:\n");
                top = -1;
                pop();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\nExiting program.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

