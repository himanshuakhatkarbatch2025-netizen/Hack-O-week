#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    char data[MAX][50];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push
void push(struct Stack *s, char task[]) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    strcpy(s->data[s->top], task);
}

// Pop
char* pop(struct Stack *s) {
    if (s->top == -1) {
        return NULL;
    }
    return s->data[s->top--];
}

// Clear stack
void clear(struct Stack *s) {
    s->top = -1;
}

// Display current tasks
void display(struct Stack *undo) {
    if (undo->top == -1) {
        printf("No tasks\n");
        return;
    }

    printf("Current Tasks:\n");
    for (int i = 0; i <= undo->top; i++) {
        printf("%s\n", undo->data[i]);
    }
}

int main() {
    struct Stack undoStack, redoStack;
    char task[50];
    int choice;

    init(&undoStack);
    init(&redoStack);

    while (1) {
        printf("\n1. Add Task\n2. Undo\n3. Redo\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter task: ");
                scanf(" %[^\n]", task); // takes full line
                push(&undoStack, task);
                clear(&redoStack); // IMPORTANT
                break;

            case 2: {
                char *t = pop(&undoStack);
                if (t == NULL) {
                    printf("Nothing to undo\n");
                } else {
                    push(&redoStack, t);
                    printf("Undo: %s\n", t);
                }
                break;
            }

            case 3: {
                char *t = pop(&redoStack);
                if (t == NULL) {
                    printf("Nothing to redo\n");
                } else {
                    push(&undoStack, t);
                    printf("Redo: %s\n", t);
                }
                break;
            }

            case 4:
                display(&undoStack);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
