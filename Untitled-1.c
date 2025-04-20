#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to hold book information
typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

// Global array to store books
Book library[MAX_BOOKS];
int numBooks = 0;

// Function to add a new book
void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;

    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter book author: ");
    scanf(" %[^\n]", newBook.author);

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    library[numBooks++] = newBook;
    printf("Book added successfully!\n");
}

// Function to search for a book by title
void searchBook() {
    char searchTitle[100];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Publication Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to display all books
void displayBooks() {
    if (numBooks == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Books in the Library:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Publication Year: %d\n", library[i].year);
        printf("--------------------\n");
    }
}

// Function to delete a book
void deleteBook() {
    if (numBooks == 0) {
        printf("Library is empty.\n");
        return;
    }

    char searchTitle[100];
    printf("Enter book title to delete: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            for (int j = i; j < numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            numBooks--;
            printf("Book deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n---- Library Management Menu ----\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display All Books\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
