#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Structure to represent a candidate
typedef struct Candidate {
    int candidateID;
    char name[50];
    int voteCount;
    struct Candidate* next;
} Candidate;

// Function to create a new candidate
Candidate* createCandidate(int candidateID, char name[]) {
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
    newCandidate->candidateID = candidateID;
    strcpy(newCandidate->name, name);
    newCandidate->voteCount = 0;
    newCandidate->next = 0;
    return newCandidate;
}

// Function to display the list of candidates
void displayCandidates(Candidate* head) {
    if (head == 0) {
        printf("No candidates available.\n");
        return;
    }
    printf("List of candidates:\n");
    Candidate* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Votes: %d\n", current->candidateID, current->name, current->voteCount);
        current = current->next;
    }
}

// Function to add a candidate to the list
void addCandidate(Candidate** head, int candidateID, char name[]) {
    Candidate* newCandidate = createCandidate(candidateID, name);
    if (*head == 0) {
        *head = newCandidate;
    } else {
        Candidate* current = *head;
        while (current->next != 0) {
            current = current->next;
        }
        current->next = newCandidate;
    }
    printf("Candidate added successfully.\n");
}

// Function to cast a vote for a candidate
void castVote(Candidate* head, int candidateID) {
    Candidate* current = head;
    while (current != 0) {
        if (current->candidateID == candidateID) {
            current->voteCount++;
            printf("Vote casted successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Invalid candidate ID. Vote not casted.\n");
}

// Function to calculate the total votes and find the winner
void calculateWinner(Candidate* head) {
    if (head == 0) {
        printf("No candidates available.\n");
        return;
    }
    Candidate* current = head;
    Candidate* winner = current;
    while (current != 0) {
        if (current->voteCount > winner->voteCount) {
            winner = current;
        }
        current = current->next;
    }
    printf("Winner: ID: %d, Name: %s, Votes: %d\n", winner->candidateID, winner->name, winner->voteCount);
}

int main() {
    Candidate* head = NULL;
    int choice, candidateID,z;
    char candidateName[50];
    

x:printf("*************Welcome to Elections of 2023************\n");
printf("*\n*\n*\n*\n\t\t**********ENTER 1 TO PROCEED************\t\n");
printf("***********************************************************\n");
scanf("%d",&z);


if (z==1)
{


    do {
        printf("\n-- Election Voting System --\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Calculate Winner\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate ID: ");
                scanf("%d", &candidateID);
                printf("Enter candidate name: ");
                scanf("%s", candidateName);
                addCandidate(&head, candidateID, candidateName);
                break;
            case 2:
                displayCandidates(head);
                break;
            case 3:
                printf("Enter candidate ID to cast your vote: ");
                scanf("%d", &candidateID);
                castVote(head, candidateID);
                break;
            case 4:
                calculateWinner(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
else
{ 
    goto x;
}
}