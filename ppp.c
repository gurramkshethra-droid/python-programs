#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for appointment
typedef struct Appointment {
    char patientName[100];
    char doctorName[100];
    char date[15];   // format: DD-MM-YYYY
    char time[10];   // format: HH:MM
    struct Appointment* next;
} Appointment;

// Head of the linked list
Appointment* head = NULL;

// Function to create a new appointment node
Appointment* createAppointment(char* pname, char* dname, char* date, char* time) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newApp->patientName, pname);
    strcpy(newApp->doctorName, dname);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;
    return newApp;
}

// Add appointment to the list
void addAppointment(char* pname, char* dname, char* date, char* time) {
    Appointment* newApp = createAppointment(pname, dname, date, time);
    if (head == NULL) {
        head = newApp;
    } else {
        Appointment* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newApp;
    }
    printf("Appointment added successfully!\n");
}

// Search by patient name
void searchAppointment(char* pname) {
    Appointment* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->patientName, pname) == 0) {
            printf("\nFound Appointment:\n");
            printf("Patient: %s\nDoctor: %s\nDate: %s\nTime: %s\n",
                temp->patientName, temp->doctorName, temp->date, temp->time);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("No appointment found for %s\n", pname);
}

// Sort appointments by time (simple bubble sort on linked list)
void sortAppointments() {
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    Appointment *ptr1;
    Appointment *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->time, ptr1->next->time) > 0) {
                // Swap data
                char tempName[100], tempDoc[100], tempDate[15], tempTime[10];
                strcpy(tempName, ptr1->patientName);
                strcpy(tempDoc, ptr1->doctorName);
                strcpy(tempDate, ptr1->date);
                strcpy(tempTime, ptr1->time);

                strcpy(ptr1->patientName, ptr1->next->patientName);
                strcpy(ptr1->doctorName, ptr1->next->doctorName);
                strcpy(ptr1->date, ptr1->next->date);
                strcpy(ptr1->time, ptr1->next->time);

                strcpy(ptr1->next->patientName, tempName);
                strcpy(ptr1->next->doctorName, tempDoc);
                strcpy(ptr1->next->date, tempDate);
                strcpy(ptr1->next->time, tempTime);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Appointments sorted by time.\n");
}

// Display all appointments
void displayAppointments() {
    Appointment* temp = head;
    if (temp == NULL) {
        printf("No appointments to display.\n");
        return;
    }
    printf("\nAll Appointments:\n");
    while (temp != NULL) {
        printf("Patient: %s | Doctor: %s | Date: %s | Time: %s\n",
            temp->patientName, temp->doctorName, temp->date, temp->time);
        temp = temp->next;
    }
}

// Main menu
int main() {
    int choice;
    char pname[100], dname[100], date[15], time[10];

    do {
        printf("\n--- Hospital Appointment Scheduling System ---\n");
        printf("1. Add Appointment\n2. Search Appointment\n3. Sort Appointments\n4. Display All\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
        case 1:
            printf("Enter Patient Name: ");
            fgets(pname, sizeof(pname), stdin); pname[strcspn(pname, "\n")] = 0;
            printf("Enter Doctor Name: ");
            fgets(dname, sizeof(dname), stdin); dname[strcspn(dname, "\n")] = 0;
            printf("Enter Date (DD-MM-YYYY): ");
            fgets(date, sizeof(date), stdin); date[strcspn(date, "\n")] = 0;
            printf("Enter Time (HH:MM): ");
            fgets(time, sizeof(time), stdin); time[strcspn(time, "\n")] = 0;
            addAppointment(pname, dname, date, time);
            break;
        case 2:
            printf("Enter Patient Name to Search: ");
            fgets(pname, sizeof(pname), stdin); pname[strcspn(pname, "\n")] = 0;
            searchAppointment(pname);
            break;
        case 3:
            sortAppointments();
            break;
        case 4:
            displayAppointments();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
