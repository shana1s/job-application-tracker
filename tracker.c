#include <stdio.h>
#include <string.h>

#define MAX_APPS 100

typedef struct {
    char company[50];
    char position[100];
    char status[30];
} Application;

Application applications[MAX_APPS];
int numApplications = 0;


void addApplication(void) {

    if (numApplications >= MAX_APPS) {
        printf("Application tracker is full.\n");
        return;
    }

    printf("\n--- Add Application ---\n");

    printf("Company: ");
    scanf(" %49[^\n]", applications[numApplications].company);

    printf("Position: ");
    scanf(" %99[^\n]", applications[numApplications].position);

    printf("Status (Applied/Interview/Rejected/Offer): ");
    scanf(" %29[^\n]", applications[numApplications].status);

    numApplications++;

    printf("Application added!\n");
}


void viewApplications(void) {

    if (numApplications == 0) {
        printf("\nNo applications saved yet.\n");
        return;
    }

    printf("\n--- Your Applications ---\n");

    for (int i = 0; i < numApplications; i++) {

        printf("\nApplication %d\n", i + 1);
        printf("Company: %s\n", applications[i].company);
        printf("Position: %s\n", applications[i].position);
        printf("Status: %s\n", applications[i].status);
    }
}


void searchApplications(void) {

    char company[50];
    int found = 0;

    printf("\nEnter company name: ");
    scanf(" %49[^\n]", company);

    for (int i = 0; i < numApplications; i++) {

        if (strcmp(applications[i].company, company) == 0) {

            printf("\nApplication found!\n");
            printf("Company: %s\n", applications[i].company);
            printf("Position: %s\n", applications[i].position);
            printf("Status: %s\n", applications[i].status);

            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo application found for that company.\n");
    }
}


void updateStatus(void) {

    int number;

    viewApplications();

    if (numApplications == 0) {
        return;
    }

    printf("\nEnter application number to update: ");
    scanf("%d", &number);

    if (number < 1 || number > numApplications) {
        printf("Invalid application number.\n");
        return;
    }

    printf("New status: ");
    scanf(" %29[^\n]", applications[number - 1].status);

    printf("Status updated!\n");
}


void viewStatistics(void) {

    int applied = 0;
    int interviews = 0;
    int rejected = 0;
    int offers = 0;

    for (int i = 0; i < numApplications; i++) {

        if (strcmp(applications[i].status, "Applied") == 0) {
            applied++;
        }

        else if (strcmp(applications[i].status, "Interview") == 0) {
            interviews++;
        }

        else if (strcmp(applications[i].status, "Rejected") == 0) {
            rejected++;
        }

        else if (strcmp(applications[i].status, "Offer") == 0) {
            offers++;
        }
    }

    printf("\n--- Application Statistics ---\n");
    printf("Total: %d\n", numApplications);
    printf("Applied: %d\n", applied);
    printf("Interviews: %d\n", interviews);
    printf("Rejected: %d\n", rejected);
    printf("Offers: %d\n", offers);
}


int main(void) {

    int choice;

    do {

        printf("\n========================\n");
        printf("|   Job App Tracker    |\n");
        printf("========================\n");

        printf("1. Add a new job application\n");
        printf("2. View all job applications\n");
        printf("3. Search applications\n");
        printf("4. Update application status\n");
        printf("5. View statistics\n");
        printf("6. Exit\n");

        printf("Please select an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addApplication();
                break;

            case 2:
                viewApplications();
                break;

            case 3:
                searchApplications();
                break;

            case 4:
                updateStatus();
                break;

            case 5:
                viewStatistics();
                break;

            case 6:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid option. Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}