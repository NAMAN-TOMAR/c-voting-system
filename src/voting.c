#include <stdio.h>
#include <string.h>
#include "voting.h"
#include "utils.h"

static Candidate candidates[MAX_CANDIDATES];
static int candidateCount = 0;

void initCandidates() {
    candidateCount = 0;
    /* Not strictly needed to set votes to 0, but we can */
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
        candidates[i].name[0] = '\0';
    }
}

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Cannot add more candidates. Maximum limit reached.\n");
        return;
    }

    printf("Enter candidate name (no spaces, max 49 chars): ");
    if (scanf("%49s", candidates[candidateCount].name) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    candidates[candidateCount].votes = 0;
    candidateCount++;

    printf("Candidate added successfully. Total candidates: %d\n", candidateCount);
}

void listCandidates() {
    if (candidateCount == 0) {
        printf("No candidates available.\n");
        return;
    }

    printf("\n----- Candidate List -----\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s (Votes: %d)\n", i + 1, candidates[i].name, candidates[i].votes);
    }
    printf("--------------------------\n");
}

void castVote() {
    if (candidateCount == 0) {
        printf("No candidates to vote for.\n");
        return;
    }

    listCandidates();
    printf("Enter candidate number to vote for: ");
    int choice = readInt();

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid candidate number.\n");
        return;
    }

    candidates[choice - 1].votes++;
    printf("Vote cast successfully for %s!\n", candidates[choice - 1].name);
}

void showResults() {
    if (candidateCount == 0) {
        printf("No candidates to show results.\n");
        return;
    }

    printf("\n----- Voting Results -----\n");
    int maxVotes = -1;
    int winnerIndex = -1;

    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);

        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("\nWinner: %s with %d votes.\n",
               candidates[winnerIndex].name,
               candidates[winnerIndex].votes);
    } else {
        printf("\nNo winner.\n");
    }

    printf("--------------------------\n");
}

