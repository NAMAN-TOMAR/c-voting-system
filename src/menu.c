#include <stdio.h>
#include <string.h>

#include "menu.h"
#include "voting.h"
#include "utils.h"

static int verifyAdminPassword() {
    char password[20];

    printf("Enter admin password: ");
    scanf("%19s", password);

    /* Simple fixed password. You can change this string. */
    if (strcmp(password, "1234") == 0) {
        return 1;
    } else {
        printf("Invalid password.\n");
        return 0;
    }
}

void showAdminMenu() {
    int choice;

    if (!verifyAdminPassword()) {
        return;
    }

    do {
        printf("\n===== Admin Menu =====\n");
        printf("1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Show results\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                listCandidates();
                break;
            case 3:
                showResults();
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
}

void showUserMenu() {
    int choice;

    do {
        printf("\n===== User Menu =====\n");
        printf("1. List candidates\n");
        printf("2. Cast vote\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice) {
            case 1:
                listCandidates();
                break;
            case 2:
                castVote();
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
}

void showMainMenu() {
    int choice;

    initCandidates();  /* Initialize candidate list at the start */

    do {
        printf("\n===== Voting System =====\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice) {
            case 1:
                showAdminMenu();
                break;
            case 2:
                showUserMenu();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while (choice != 0);
}

