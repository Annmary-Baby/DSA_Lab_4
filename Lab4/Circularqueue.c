#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int emp_id;
    char position[30];
    struct employee *next;
} *head, *tail;

int numberOfEmployees = 0;

int createEmployee() {
    char ch;
    while (1) {
        struct employee *newEmployee = (struct employee *)malloc(sizeof(struct employee));
        if (newEmployee == NULL) {
            printf("Memory allocation error!!");
            return 0;
        }

        printf("\nEnter Employee Name: ");
        scanf("%s", newEmployee->name);
        printf("Enter Employee ID: ");
        scanf("%d", &newEmployee->emp_id);
        printf("Enter Employee Position: ");
        scanf("%s", newEmployee->position);

        numberOfEmployees++;
        newEmployee->next = NULL;

        if (head == NULL) {
            head = tail = newEmployee;
            last->next = head;
        } else {
            tail->next = newEmployee;
            tail = newEmployee;
            tail->next = head;
        }

        printf("Want to add more employees (Y/N)?");
        ch = getch();
        if (ch == 'n' || ch == 'N') {
            return 0;
        }
    }
}

void displayEmployeeList() {
    struct employee *temp = head;
    if (temp == NULL) {
        printf("There are no employees In Queue!!\n");
        return;
    }

    do {
        printf("ID: %d, Name: %s, Position: %s\n", temp->emp_id, temp->name, temp->position);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void addEmployee() {
    struct employee *newEmployee = (struct employee *)malloc(sizeof(struct employee));
    if (newEmployee == NULL) {
        printf("Memory allocation error");
        return;
    }

    printf("\nEnter Employee Name: ");
    scanf("%s", newEmployee->name);
    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee->emp_id);
    printf("Enter Employee Position: ");
    scanf("%s", newEmployee->position);

    numberOfEmployees++;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = tail = newEmployee;
        last->next = head;
    } else {
        tail->next = newEmployee;
        tail = newEmployee;
        tail->next = head;
    }
}

void removeEmployee() {
    if (head == NULL) {
        printf("\nThere are no employees in Queue");
    } else {
        struct employee *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
        numberOfEmployees--;
        printf("\nEmployee removed from Queue\n");
    }
}

void searchEmployee() {
    int search_id;
    int foundFlag = 0;
    struct employee *temp = head;

    printf("\nEnter ID of the employee you want to find: ");
    scanf("%d", &search_id);

    do {
        if (search_id == temp->emp_id) {
            foundFlag = 1;
            printf("\nEmployee Found!\n");
            printf("ID: %d, Name: %s, Position: %s\n", temp->emp_id, temp->name, temp->position);
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (foundFlag == 0) {
        printf("\nNo employee found with the given ID in Queue!!\n");
    }
}

void exit_program() {
    struct employee *temp = head;
    while (temp != NULL) {
        struct employee *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

int main() {
    int opt;
    opt = 0;
    head = tail = NULL;

    while (1) {
        printf("\n");
        printf(" +--------------HR Management Menu--------------+\n");
        printf(" | 1. Create Employee Queue                       |\n");
        printf(" | 2. Display Employee List                      |\n");
        printf(" | 3. Add Employee                               |\n");
        printf(" | 4. Remove Employee                            |\n");
        printf(" | 5. Search Employee                             |\n");
        printf(" | 6. Exit                                       |\n");
        printf(" +-----------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                createEmployee();
                break;
            case 2:
                displayEmployeeList();
                break;
            case 3:
                addEmployee();
                break;
            case 4:
                removeEmployee();
                break;
            case 5:
                searchEmployee();
                break;
            case 6:
                exit_program();
        }
    }
    return 0;
}