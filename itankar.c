#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a profile
struct Profile {
    char name[50];
    int age;
    char gender[10];
    char contact[20];
    struct Profile* next;
};

// Function to create a new profile
struct Profile* createProfile() {
    struct Profile* newProfile = (struct Profile*)malloc(sizeof(struct Profile));
    printf("Enter Name: ");
    scanf("%s", newProfile->name);
    printf("Enter Age: ");
    scanf("%d", &newProfile->age);

    printf("Enter Gender: ");
    scanf("%s", newProfile->gender);
    printf("Enter Contact: ");
    scanf("%s", newProfile->contact);
    newProfile->next = NULL;
    return newProfile;
}

// Function to add a profile to the list
void addProfile(struct Profile** head) {
    struct Profile* newProfile = createProfile();
    if (*head == NULL) {
        *head = newProfile;
    } else {
        struct Profile* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProfile;
    }

    printf("Profile added successfully!\n");
}

// Function to delete a profile from the list
void deleteProfile(struct Profile** head, char* name) {
    if (*head == NULL) {
        printf("No profiles found!\n");
        return;
    }
    struct Profile* current = *head;
    struct Profile* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);

            printf("Profile deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Profile not found!\n");
}

// Function to search for a profile by name
void searchProfile(struct Profile* head, char* name) {
    if (head == NULL) {
        printf("No profiles found!\n");
        return;
    }
    struct Profile* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {

            printf("Name: %s\n", current->name);
            printf("Age: %d\n", current->age);
            printf("Gender: %s\n", current->gender);
            printf("Contact: %s\n", current->contact);
            return;
        }
        current = current->next;
    }
    printf("Profile not found!\n");
}

// Function to display all profiles
void displayProfiles(struct Profile* head) {
    if (head == NULL) {
        printf("No profiles found!\n");
        return;
    }
    struct Profile* current = head;
    while (current != NULL) {

        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Gender: %s\n", current->gender);
        printf("Contact: %s\n", current->contact);
        printf("----------------------\n");
        current = current->next;
    }
}

// Function to clear the list and free memory
void clearList(struct Profile** head) {
    struct Profile* current = *head;
    struct Profile* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;

    printf("List cleared successfully!\n");
}

int main() {
    struct Profile* head = NULL;
    int choice;
    char name[50];

    do {
        printf("------ Matrimonial System ------\n");
        printf("1. Add Profile\n");
        printf("2. Delete Profile\n");
        printf("3. Search Profile\n");
        printf("4. Display All Profiles\n");
        printf("5. Clear List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addProfile(&head);
                break;
            case 2:
                printf("Enter the name of the profile to delete: ");
                scanf("%s", name);
                deleteProfile(&head, name);
                break;
            case 3:
                printf("Enter the name of the profile to search: ");
                scanf("%s", name);
                searchProfile(head, name);
                break;
            case 4:
                displayProfiles(head);
                break;
            case 5:
                clearList(&head);
                break;

            case 6:
                printf("Exiting...Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 6);

    return 0;
}
