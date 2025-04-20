#include<stdio.h>
#include<stdlib.h>
#define max 6

int stack[max];
int top = -1;

void push(void) {
    int item;
    printf("ENTER NUMBER TO BE PUSHED: ");
    scanf("%d", &item);
    top++;
    stack[top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value indicating an error
    }
    return stack[top--];
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("The top value at the top of stack is %d\n", stack[top]);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    for (i = top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("******\nENTER YOUR CHOICE\n1. PUSH\n2. POP\n3. PEEK\n4. Display\n5. Exit\n******\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}