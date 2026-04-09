#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Check if empty
int isEmpty() {
    return front == -1;
}

// Enqueue
void enqueue(int x) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
    printf("Customer %d added\n", x);
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Customer %d served\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main
int main() {
    int choice, x;

    while (1) {
        printf("\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
