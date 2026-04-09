#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

// Function to read contacts
void readContacts(struct Contact c[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", c[i].name);
        printf("Enter phone: ");
        scanf("%s", c[i].phone);
    }
}

// Function to display contacts
void displayContacts(struct Contact c[], int n) {
    printf("\nContacts List:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", c[i].name, c[i].phone);
    }
}

// Bubble Sort by name
void sortContacts(struct Contact c[], int n) {
    struct Contact temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(c[j].name, c[j + 1].name) > 0) {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}

// Binary Search by name
int binarySearch(struct Contact c[], int n, char key[]) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        int cmp = strcmp(c[mid].name, key);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Main function
int main() {
    struct Contact contacts[MAX];
    int n;
    char searchName[50];

    printf("Enter number of contacts: ");
    scanf("%d", &n);

    readContacts(contacts, n);

    sortContacts(contacts, n);

    displayContacts(contacts, n);

    printf("\nEnter name to search: ");
    scanf("%s", searchName);

    int pos = binarySearch(contacts, n, searchName);

    if (pos != -1)
        printf("Found: %s - %s\n", contacts[pos].name, contacts[pos].phone);
    else
        printf("Contact not found\n");

    return 0;
}
