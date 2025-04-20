#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
typedef struct Candidate {
    char name[50];
    char party[50];
    int voteCount;
} Candidate;

// Function to register a new candidate
void registerCandidate(Candidate** candidates, int* numCandidates) {
    char name[50], party[50];
    
    printf("Enter candidate name: ");
    scanf("%s", name);
    printf("Enter candidate party: ");
    scanf("%s", party);
    
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(newCandidate->name, name);
    strcpy(newCandidate->party, party);
    newCandidate->voteCount = 0;
    
    (candidates) = (Candidate*)realloc(*candidates, (*numCandidates + 1) * sizeof(Candidate));
    (*candidates)[*numCandidates] = *newCandidate;
    (*numCandidates)++;
    
    printf("Candidate registered successfully!\n");
}

// Function to cast a vote for a candidate
void castVote(Candidate* candidates, int numCandidates) {
    int candidateIndex;
    
    printf("Enter the index of the candidate you want to vote for: ");
    scanf("%d", &candidateIndex);
    
    if (candidateIndex >= 0 && candidateIndex < numCandidates) {
        candidates[candidateIndex].voteCount++;
        printf("Vote cast successfully!\n");
    } else {
        printf("Invalid candidate index!\n");
    }
}

// Function to display the voting results
void displayResults(Candidate* candidates, int numCandidates) {
    printf("Voting Results:\n");
    printf("-------------------------------\n");
    printf("Candidate\t\tParty\t\tVote Count\n");
    printf("-------------------------------\n");
    
    for (int i = 0; i < numCandidates; i++) {
        printf("%s\t\t%s\t\t%d\n", candidates[i].name, candidates[i].party, candidates[i].voteCount);
    }
    
    printf("-------------------------------\n");
}

int main() {
    Candidate* candidates = NULL;
    int numCandidates = 0;
    int choice;
    
    do {
        printf("Mini Voting System\n");
        printf("-------------------\n");
        printf("1. Register Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerCandidate(&candidates, &numCandidates);
                break;
            case 2:
                castVote(candidates, numCandidates);
                break;
            case 3:
                displayResults(candidates, numCandidates);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\n");
    } while (choice != 4);
    
    // Free dynamically allocated memory
    free(candidates);
    
    return 0;
}