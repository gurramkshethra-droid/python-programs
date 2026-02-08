#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int code;
    char doj[15];  // DD-MM-YYYY
    float basic, hra, da, ca, total;
    struct Employee *next;
};

struct Employee *last = NULL; // Circular Linked List last pointer

// Function to create a new node
struct Employee* createNode() {
    struct Employee newNode = (struct Employee)malloc(sizeof(struct Employee));
    printf("\nEnter Employee Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter Employee Code: ");
    scanf("%d", &newNode->code);
    printf("Enter Date of Joining (DD-MM-YYYY): ");
    scanf("%s", newNode->doj);
    printf("Enter Basic, HRA, DA, CA: ");
    scanf("%f %f %f %f", &newNode->basic, &newNode->hra, &newNode->da, &newNode->ca);
    newNode->total = newNode->basic + newNode->hra + newNode->da + newNode->ca;
    newNode->next = NULL;
    return newNode;
}

// Add Employee
void addEmployee() {
    struct Employee *newNode = createNode();
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("\nEmployee added successfully!\n");
}

// Delete Employee by code
void deleteEmployee(int code) {
    if (last == NULL) {
        printf("\nNo employees to delete.\n");
        return;
    }
    struct Employee *temp = last->next, *prev = last;
    do {
        if (temp->code == code) {
            if (temp == last && temp->next == last) {
                last = NULL;
            } else {
                prev->next = temp->next;
                if (temp == last) last = prev;
            }
            free(temp);
            printf("\nEmployee deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
    printf("\nEmployee not found!\n");
}

// Modify Employee by code
void modifyEmployee(int code) {
    if (last == NULL) {
        printf("\nNo employees.\n");
        return;
    }
    struct Employee *temp = last->next;
    do {
        if (temp->code == code) {
            printf("\nEnter new details for Employee (Code %d)\n", code);
            printf("Enter Name: ");
            scanf(" %[^\n]", temp->name);
            printf("Enter Date of Joining: ");
            scanf("%s", temp->doj);
            printf("Enter Basic, HRA, DA, CA: ");
            scanf("%f %f %f %f", &temp->basic, &temp->hra, &temp->da, &temp->ca);
            temp->total = temp->basic + temp->hra + temp->da + temp->ca;
            printf("\nEmployee modified successfully!\n");
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
    printf("\nEmployee not found!\n");
}

// Search Employee by code
void searchEmployee(int code) {
    if (last == NULL) {
        printf("\nNo employees.\n");
        return;
    }
    struct Employee *temp = last->next;
    do {
        if (temp->code == code) {
            printf("\nEmployee Found:\n");
            printf("%-10s %-5s %-12s %-8s\n", "Name", "Code", "DOJ", "Total");
            printf("%-10s %-5d %-12s %-8.2f\n", temp->name, temp->code, temp->doj, temp->total);
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
    printf("\nEmployee not found!\n");
}

// Display all employees
void displayEmployees() {
    if (last == NULL) {
        printf("\nNo employees to display.\n");
        return;
    }
    struct Employee *temp = last->next;
    printf("\n%-15s %-10s %-15s %-10s %-10s %-10s %-10s %-10s\n",
           "Name", "Code", "DOJ", "Basic", "HRA", "DA", "CA", "Total");
    do {
        printf("%-15s %-10d %-15s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
               temp->name, temp->code, temp->doj,
               temp->basic, temp->hra, temp->da, temp->ca, temp->total);
        temp = temp->next;
    } while (temp != last->next);
}

// Delete all employees
void deleteAll() {
    if (last == NULL) return;
    struct Employee *temp = last->next;
    while (temp != last) {
        struct Employee *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(last);
    last = NULL;
    printf("\nAll employees deleted.\n");
}

// Main Menu
int main() {
    int choice, code;
    while (1) {
        printf("\n---- Employee Management Menu ----\n");
        printf("1. Add Employee\n2. Delete Employee\n3. Modify Employee\n4. Search Employee\n5. Display All Employees\n6. Delete All Employees\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: 
                printf("Enter Employee Code to delete: ");
                scanf("%d", &code);
                deleteEmployee(code); break;
            case 3: 
                printf("Enter Employee Code to modify: ");
                scanf("%d", &code);
                modifyEmployee(code); break;
            case 4: 
                printf("Enter Employee Code to search: ");
                scanf("%d", &code);
                searchEmployee(code); break;
            case 5: displayEmployees(); break;
            case 6: deleteAll(); break;
            case 7: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}