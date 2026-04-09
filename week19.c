#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[50];
    struct Node *prev, *next;
};

// Create node
struct Node* createNode(char song[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
struct Node* insertFront(struct Node* head, char song[]) {
    struct Node* newNode = createNode(song);

    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }

    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, char song[]) {
    struct Node* newNode = createNode(song);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete by position
struct Node* deletePos(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct Node* temp = head;

    // delete first node
    if (pos == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    return head;
}

// Reverse list (Shuffle)
struct Node* reverse(struct Node* head) {
    struct Node *temp = NULL, *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

// Display
void display(struct Node* head) {
    if (head == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Playlist:\n");
    while (temp != NULL) {
        printf("%s\n", temp->song);
        temp = temp->next;
    }
}

// Main
int main() {
    struct Node* head = NULL;
    int choice, pos;
    char song[50];

    while (1) {
        printf("\n1. Add Song Front\n2. Add Song End\n3. Delete by Position\n4. Shuffle (Reverse)\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", song);
                head = insertFront(head, song);
                break;

            case 2:
                printf("Enter song name: ");
                scanf(" %[^\n]", song);
                head = insertEnd(head, song);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deletePos(head, pos);
                break;

            case 4:
                head = reverse(head);
                printf("Playlist shuffled (reversed)\n");
                break;

            case 5:
                display(head);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
