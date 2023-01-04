#include <stdio.h>
#include <limits.h>
/* a beginner's stack implementation */
#define MAXSTK 10

struct Stack {
    int top;
    int items[MAXSTK];
};

typedef struct Stack stack;

void display(stack stk) {
    int p = stk.top;
    puts("-------------");
    while (p >= 0) {
        putchar('|');
        printf("%11d", stk.items[p]);
        puts("|");
        --p;
    }
    puts("-------------");
}

void push(stack *stk, int x) {
    if (stk->top == MAXSTK-1) {
        puts("Overflow.");
        return;
    }

    stk->top += 1;
    // printf("Pushing %d at %d ...\n", x, stk.top);
    stk->items[stk->top] = x;
}

int pop(stack *stk) {
    if (stk->top == -1) {
        puts("Underflow.");
        return INT_MAX;
    }

    // printf("Popping %d at %d ...\n",stk.items[stk.top], stk.top);
    int popped;
    popped = stk->items[stk->top];
    stk->top -=1;
    return popped;
}

int main() {
    stack mystack;
    mystack.top = -1;

    int pushed;
    int popped;
    char choice = 0;
    while (choice != '4') {

        puts("\nChoose Operation: ");
        puts("1) Push");
        puts("2) Pop");
        puts("3) Display");
        puts("4) Quit");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                puts("Enter value to push: ");
                scanf("%d", &pushed);
                push(&mystack, pushed);
                break;

            case '2':
                popped = pop(&mystack);
                printf("%d was popped from stack.\n", popped);
                break;

            case '3':
                display(mystack);
                break;

            case '4':
                puts("Bye :)");
                break;

            default:
                puts("Unknown Input");
        }
    }
    return 0;
}
