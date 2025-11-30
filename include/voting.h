#ifndef VOTING_H
#define VOTING_H

#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

/* Initialize candidate list */
void initCandidates();

/* Add a new candidate */
void addCandidate();

/* List all candidates (for both admin and user) */
void listCandidates();

/* Cast a vote for a selected candidate */
void castVote();

/* Show all results and declare winner */
void showResults();

#endif

