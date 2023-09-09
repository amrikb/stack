#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // You can choose a different value for underflow
    } else {
        int item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

// Function to peek at the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // You can choose a different value for an empty stack
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Top element after pop: %d\n", peek(&stack));

    return 0;
}
