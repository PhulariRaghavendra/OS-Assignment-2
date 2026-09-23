#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROCESSES 100

struct Process {
    int pid;
    char name[50];
    int priority;
    char state[20];
};

struct Process processes[MAX_PROCESSES];
int n = 0;


/* Function to convert state to uppercase */
void convertToUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}


/* Function to enter process details */
void enterProcesses() {
    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes.\n");
        n = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Process %d ---\n", i + 1);

        printf("Enter PID: ");
        scanf("%d", &processes[i].pid);

        printf("Enter Process Name: ");
        scanf("%49s", processes[i].name);

        printf("Enter Priority: ");
        scanf("%d", &processes[i].priority);

        printf("Enter State (Ready/Running/Waiting/Terminated): ");
        scanf("%19s", processes[i].state);

        /* Convert state to uppercase */
        convertToUpperCase(processes[i].state);
    }

    printf("\nProcess details entered successfully!\n");
}


/* Function to display all process details */
void displayProcesses() {
    if (n == 0) {
        printf("\nNo processes available.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("              ALL PROCESS DETAILS\n");
    printf("====================================================\n");

    printf("%-10s %-20s %-10s %-15s\n",
           "PID", "Name", "Priority", "State");

    printf("----------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-10d %-15s\n",
               processes[i].pid,
               processes[i].name,
               processes[i].priority,
               processes[i].state);
    }
}


/* Function to display highest priority process */
void displayHighestPriority() {
    if (n == 0) {
        printf("\nNo processes available.\n");
        return;
    }

    int highest = 0;

    for (int i = 1; i < n; i++) {
        if (processes[i].priority > processes[highest].priority) {
            highest = i;
        }
    }

    printf("\n========================================\n");
    printf("       HIGHEST PRIORITY PROCESS\n");
    printf("========================================\n");

    printf("PID      : %d\n", processes[highest].pid);
    printf("Name     : %s\n", processes[highest].name);
    printf("Priority : %d\n", processes[highest].priority);
    printf("State    : %s\n", processes[highest].state);
}


/* Function to display processes by state */
void displayProcessesByState() {
    if (n == 0) {
        printf("\nNo processes available.\n");
        return;
    }

    char requiredState[20];
    int found = 0;

    printf("\nEnter state to search for: ");
    scanf("%19s", requiredState);

    /* Convert entered state to uppercase */
    convertToUpperCase(requiredState);

    printf("\nProcesses in %s state:\n", requiredState);

    printf("%-10s %-20s %-10s\n",
           "PID", "Name", "Priority");

    printf("---------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (strcmp(processes[i].state, requiredState) == 0) {
            printf("%-10d %-20s %-10d\n",
                   processes[i].pid,
                   processes[i].name,
                   processes[i].priority);

            found = 1;
        }
    }

    if (!found) {
        printf("No processes found in %s state.\n", requiredState);
    }
}


/* Function to change process state */
void changeProcessState() {
    if (n == 0) {
        printf("\nNo processes available.\n");
        return;
    }

    int pid;
    char newState[20];
    int found = 0;

    printf("\nEnter PID of the process: ");
    scanf("%d", &pid);

    for (int i = 0; i < n; i++) {
        if (processes[i].pid == pid) {

            printf("Process found: %s\n", processes[i].name);
            printf("Current State: %s\n", processes[i].state);

            printf("Enter New State (Ready/Running/Waiting/Terminated): ");
            scanf("%19s", newState);

            /* Convert new state to uppercase */
            convertToUpperCase(newState);

            strcpy(processes[i].state, newState);

            printf("\nProcess state changed successfully!\n");
            printf("New State: %s\n", processes[i].state);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProcess with PID %d not found.\n", pid);
    }
}


/* Function to display current state of all processes */
void displayCurrentStates() {
    if (n == 0) {
        printf("\nNo processes available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("        CURRENT PROCESS STATES\n");
    printf("========================================\n");

    printf("%-10s %-20s %-15s\n",
           "PID", "Name", "Current State");

    printf("-----------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-15s\n",
               processes[i].pid,
               processes[i].name,
               processes[i].state);
    }
}


/* Main function */
int main() {
    int choice;

    printf("========================================\n");
    printf("      PROCESS MANAGEMENT SIMULATOR\n");
    printf("========================================\n");

    enterProcesses();

    do {
        printf("\n\n");

        printf("1. Display All Process Details\n");
        printf("2. Display Highest Priority Process\n");
        printf("3. Display Processes by State\n");
        printf("4. Change Process State\n");
        printf("5. Display Current State of All Processes\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                displayProcesses();
                break;

            case 2:
                displayHighestPriority();
                break;

            case 3:
                displayProcessesByState();
                break;

            case 4:
                changeProcessState();
                break;

            case 5:
                displayCurrentStates();
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}