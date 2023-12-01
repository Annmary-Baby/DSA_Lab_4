#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int emp_id;
    int priority;
    struct employee* next;
};

struct employee* front = NULL;

void addEmployeeWithPriority() {
    struct employee* newEmployee = (struct employee*)malloc(sizeof(struct employee));
    if (newEmployee == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Employee Name: ");
    scanf("%s", newEmployee->name);

    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee->emp_id);

    printf("Enter Priority (1 for regular, 2 for VIP, etc.): ");
    scanf("%d", &newEmployee->priority);

    newEmployee->next = NULL;

    if (front == NULL || newEmployee->priority < front->priority) {
        newEmployee->next = front;
        front = newEmployee;
    } else {
        struct employee* temp = front;
        while (temp->next != NULL && temp->next->priority <= newEmployee->priority) {
            temp = temp->next;
        }
        newEmployee->next = temp->next;
        temp->next = newEmployee;
    }

    printf("\nEmployee added: %s with Priority %d!\n", newEmployee->name, newEmployee->priority);
}

void removeEmployee() {
    if (front == NULL) {
        printf("\nThere are no employees in the Priority Queue!\n");
    } else {
        struct employee* temp = front;
        front = front->next;
        free(temp);
        printf("\nHighest Priority Employee Removed!\n");
    }
}

void displayPriorityQueue() {
    struct employee* temp = front;

    if (temp == NULL) {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("[%s, ID: %d, Priority: %d] <-- ", temp->name, temp->emp_id, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int opt;

    while (1) {
        printf("\n");
        printf(" +-------------HR Management Menu-------------+\n");
        printf(" | 1. Add Employee with Priority               |\n");
        printf(" | 2. Remove Highest Priority Employee         |\n");
        printf(" | 3. Display Priority Queue                    |\n");
        printf(" | 4. Exit                                      |\n");
        printf(" +----------------------------------------------+\n");
        printf("Enter your option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                addEmployeeWithPriority();
                break;
            case 2:
                removeEmployee();
                break;
            case 3:
                displayPriorityQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}