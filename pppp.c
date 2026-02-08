#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int idcounter = 1;
// Define structure for appointment
typedef struct Appointment {
     int id;
    char patientName[100];
    char doctorName[100];
    char date[15];   // format: DD-MM-YYYY
    char time[10];   // format: HH:MM
    char meridian[5];   // AM or PM
    struct Appointment* next;
} Appointment;
Appointment* head = NULL;
// Function to create a new appointment node
Appointment* createAppointment(char* pname, char* dname, char* date, char* time, char* meridian) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    newApp->id = idcounter++;
    strcpy(newApp->patientName, pname);
    strcpy(newApp->doctorName, dname);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    strcpy(newApp->meridian,meridian);
    newApp->next = NULL;
    return newApp;
}
// Add appointment to the list
void addAppointment(char* pname, char* dname, char* date, char* time, char* meridian) {
    Appointment* newApp = createAppointment(pname, dname, date, time,meridian);
    if (head == NULL) {
        head = newApp;
    } else {
        Appointment* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newApp;
    }
    printf("Appointment with ID %d added successfully.\n", newApp->id);
}
// Search by patient name
void searchAppointment(char* pname) {
    Appointment* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->patientName, pname) == 0) {
            printf("\nFound Appointment:\n");
            printf("ID: %d\nPatient: %s\nDoctor: %s\nDate: %s\nTime: %s %s\n",
                temp->id, temp->patientName, temp->doctorName, temp->date, temp->time, temp->meridian);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("No appointment found for %s\n", pname);
}
int timeToMinutes(const char* timeStr, const char* meridian) {
    int hour = 0, minute = 0;

    // Extract hour and minute
    sscanf(timeStr, "%d:%d", &hour, &minute);

    // Convert meridiem to uppercase manually
    char mer[3];
    mer[0] = toupper(meridian[0]);
    mer[1] = toupper(meridian[1]);
    mer[2] = '\0';

    // Convert to 24-hour format
    if (strcmp(mer, "PM") == 0 && hour != 12)
        hour += 12;
    if (strcmp(mer, "AM") == 0 && hour == 12)
        hour = 0;

    return hour * 60 + minute;
}
// Sort appointments by time (simple bubble sort on linked list)
void sortAppointments() {
 if (head == NULL || head->next == NULL)
        return;
 struct Appointment *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            int time1 = timeToMinutes(i->time, i->meridian);
            int time2 = timeToMinutes(j->time, j->meridian);
            if (time1 > time2) {
                // Swap content
                struct Appointment  *temp;
                temp = i;
                i = j;
                j = temp;
                // next pointers
                struct Appointment *t;
                t=i->next;
                i->next=j->next;
                j->next=t;
            }
        }
    }

    printf(" Appointments sorted by time!\n");
}
//deletion of appointment
void deleteAppointment(int id) {
    Appointment *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf(" Appointment with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL)
        head = temp->next; // deleting head
    else
        prev->next = temp->next;

    free(temp);
    printf(" Appointment with ID %d deleted successfully.\n", id);
}
// Display all appointments
void displayAppointments() {
    Appointment* temp = head;
    if (temp == NULL) {
        printf("No appointments found.\n");
        return;
    }
    printf("\n--- All Appointments ---\n");
    while (temp != NULL) {
        printf("ID: %d | Patient: %s | Doctor: %s | Date: %s | Time: %s %s\n",
            temp->id, temp->patientName, temp->doctorName, temp->date, temp->time, temp->meridian);
        temp = temp->next;
    }
}
int main() {
    int choice;
    char pname[100], dname[100], date[15], time[10] ,meridian[5];
    int idToDelete;

    do {
        printf("\n--- Hospital Appointment Scheduling System ---\n");
        printf("1. Add Appointment\n2. Search Appointment\n3. Sort Appointments\n4. Display All\n5. Delete Appointment\n6. Exit\n");
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
            printf("Enter AM or PM: ");
            fgets(meridian, sizeof(meridian), stdin);meridian[strcspn(meridian, "\n")] = 0;
            addAppointment(pname, dname, date, time, meridian);
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
            printf("Enter Appointment ID to Delete: ");
            scanf("%d", &idToDelete);
            deleteAppointment(idToDelete);
             break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}

