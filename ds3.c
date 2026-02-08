#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Car details
typedef struct Car {
    char modelName[50];
    int modelYear;
    char brand[30];
    char fuelType[10];
    struct Car *prev, *next;
} Car;

Car *front = NULL, *rear = NULL; // Double ended queue pointers

// Function to create new car node
Car* createCar(char model[], int year, char brand[], char fuel[]) {
    Car *newCar = (Car*)malloc(sizeof(Car));
    strcpy(newCar->modelName, model);
    newCar->modelYear = year;
    strcpy(newCar->brand, brand);
    strcpy(newCar->fuelType, fuel);
    newCar->prev = newCar->next = NULL;
    return newCar;
}

// Add car at rear (new stock arrival)
void addRear() {
    char model[50], brand[30], fuel[10];
    int year;

    printf("\nEnter Model Name: ");
    scanf("%s", model);
    printf("Enter Model Year: ");
    scanf("%d", &year);
    printf("Enter Brand: ");
    scanf("%s", brand);
    printf("Enter Fuel Type (Petrol/Diesel): ");
    scanf("%s", fuel);

    Car *newCar = createCar(model, year, brand, fuel);

    if (rear == NULL) {
        front = rear = newCar;
    } else {
        rear->next = newCar;
        newCar->prev = rear;
        rear = newCar;
    }
    printf("\nCar added at rear successfully!\n");
}

// Add car at front (urgent stock)
void addFront() {
    char model[50], brand[30], fuel[10];
    int year;

    printf("\nEnter Model Name: ");
    scanf("%s", model);
    printf("Enter Model Year: ");
    scanf("%d", &year);
    printf("Enter Brand: ");
    scanf("%s", brand);
    printf("Enter Fuel Type (Petrol/Diesel): ");
    scanf("%s", fuel);

    Car *newCar = createCar(model, year, brand, fuel);

    if (front == NULL) {
        front = rear = newCar;
    } else {
        newCar->next = front;
        front->prev = newCar;
        front = newCar;
    }
    printf("\nCar added at front successfully!\n");
}

// Sell car from front (old stock)
void sellFront() {
    if (front == NULL) {
        printf("\nNo cars available.\n");
        return;
    }
    Car *temp = front;
    printf("\nCar Sold from Front: %s (%d)\n", temp->modelName, temp->modelYear);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

// Sell car from rear (latest stock)
void sellRear() {
    if (rear == NULL) {
        printf("\nNo cars available.\n");
        return;
    }
    Car *temp = rear;
    printf("\nCar Sold from Rear: %s (%d)\n", temp->modelName, temp->modelYear);

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

// Search a car
void searchCar() {
    if (front == NULL) {
        printf("\nNo cars available.\n");
        return;
    }
    char model[50];
    printf("\nEnter Model Name to search: ");
    scanf("%s", model);

    Car *temp = front;
    while (temp != NULL) {
        if (strcmp(temp->modelName, model) == 0) {
            printf("\nCar Found!\n");
            printf("Model: %s, Year: %d, Brand: %s, Fuel: %s\n",
                   temp->modelName, temp->modelYear, temp->brand, temp->fuelType);
            return;
        }
        temp = temp->next;
    }
    printf("\nCar not found.\n");
}

// Display all cars
void displayCars() {
    if (front == NULL) {
        printf("\nNo cars available.\n");
        return;
    }
    Car *temp = front;
    printf("\n%-15s %-8s %-12s %-10s\n", "Model", "Year", "Brand", "Fuel");
    while (temp != NULL) {
        printf("%-15s %-8d %-12s %-10s\n",
               temp->modelName, temp->modelYear, temp->brand, temp->fuelType);
        temp = temp->next;
    }
}

// Delete all cars
void deleteAllCars() {
    Car *temp = front;
    while (temp != NULL) {
        Car *nextCar = temp->next;
        free(temp);
        temp = nextCar;
    }
    front = rear = NULL;
    printf("\nAll cars deleted!\n");
}

// MENU
int main() {
    int choice;
    while (1) {
        printf("\n--- Car Store Management System ---\n");
        printf("1. Add Car at Rear (New Stock)\n");
        printf("2. Add Car at Front (Urgent Stock)\n");
        printf("3. Sell Car from Front (Old Stock)\n");
        printf("4. Sell Car from Rear (Latest Stock)\n");
        printf("5. Search Car\n");
        printf("6. Display All Cars\n");
        printf("7. Delete All Cars\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRear(); break;
            case 2: addFront(); break;
            case 3: sellFront(); break;
            case 4: sellRear(); break;
            case 5: searchCar(); break;
            case 6: displayCars(); break;
            case 7: deleteAllCars(); break;
            case 8: exit(0);
            default: printf("\nInvalid choice.\n");
        }
    }
    return 0;
}