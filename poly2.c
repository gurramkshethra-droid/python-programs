#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct node* createnode(int coeff, int exp) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}

// Insert in descending order, merge if exponent already exists
struct node* insertnode(struct node* head, int coeff, int exp) {
    if (coeff == 0) return head; // Skip 0 terms

    struct node* newnode = createnode(coeff, exp);

    // Case 1: Insert at head or before first node
    if (head == NULL || exp > head->exp) {
        newnode->next = head;
        return newnode;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    // Traverse to find correct position
    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    // Case 2: Exponent already exists → add coefficients
    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;
        free(newnode); // No need for new node
        return head;
    }

    // Case 3: Insert between prev and temp
    newnode->next = temp;
    prev->next = newnode;

    return head;
}

struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node* temp1 = poly1;
    struct node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            result = insertnode(result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp) {
            result = insertnode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else {
            result = insertnode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        result = insertnode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        result = insertnode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    // Polynomial 1: 5x^2 + 3x^1 + 7x^0
    poly1 = insertnode(poly1, 5, 2);
    poly1 = insertnode(poly1, 3, 1);
    poly1 = insertnode(poly1, 7, 0);

    // Polynomial 2: 2x^1 + 4x^0
    poly2 = insertnode(poly2, 2, 1);
    poly2 = insertnode(poly2, 4, 0);

    printf("First polynomial: ");
    display(poly1);

    printf("Second polynomial: ");
    display(poly2);

    struct node* result = addPolynomials(poly1, poly2);
    printf("Resultant polynomial: ");
    display(result);

    return 0;
}