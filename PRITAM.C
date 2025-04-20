#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_FRIENDS 50
#define MAX_NAME_LENGTH 50

// Structure to represent a user
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int numFriends;
    int friends[MAX_FRIENDS];
} User;

// Global array to store users
User users[MAX_USERS];
int numUsers = 0;

// Function to create a new user
void createUser() {
    User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    newUser.numFriends = 0;
    users[numUsers++] = newUser;
    printf("User created successfully!\n");
}

// Function to add a friend
void addFriend() {
    int userId, friendId;
    printf("Enter user ID: ");
    scanf("%d", &userId);
    if (userId < 0 || userId >= numUsers) {
        printf("Invalid user ID!\n");
        return;
    }
    printf("Enter friend ID: ");
    scanf("%d", &friendId);
    if (friendId < 0 || friendId >= numUsers) {
        printf("Invalid friend ID!\n");
        return;
    }
    if (userId == friendId) {
        printf("Cannot add self as a friend!\n");
        return;
    }
    User* user = &users[userId];
    if (user->numFriends == MAX_FRIENDS) {
        printf("User's friend list is full!\n");
        return;
    }
    for (int i = 0; i < user->numFriends; i++) {
        if (user->friends[i] == friendId) {
            printf("Friend already exists!\n");
            return;
        }
    }
    user->friends[user->numFriends++] = friendId;
    printf("Friend added successfully!\n");
}

// Function to view user's information
void viewUserInfo() {
    int userId;
    printf("Enter user ID: ");
    scanf("%d", &userId);
    if (userId < 0 || userId >= numUsers) {
        printf("Invalid user ID!\n");
        return;
    }
    User* user = &users[userId];
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Friends (%d):\n", user->numFriends);
    for (int i = 0; i < user->numFriends; i++) {
        User* friend = &users[user->friends[i]];
        printf("- %s\n", friend->name);
    }
}

int main() {
    int choice;
    do {
        printf("\nSocial Networking Site\n");
        printf("1. Create User\n");
        printf("2. Add Friend\n");
        printf("3. View User Info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                addFriend();
                break;
            case 3:
                viewUserInfo();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}