#include<stdio.h>
#include<stdlib.h>
struct node {
    int exp;
    int coef;
    struct node *next;
};
struct node *temp=NULL, *poly1=NULL, *poly2=NULL,*result=NULL;
struct node *create(int coef, int exp)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=coef;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode;

}
void insert(struct node** poly, int coef, int exp)
{
    struct node *newnode=create(coef,exp);
    if(*poly==NULL)
    {
        *poly=newnode;
        return;
    }
    temp=*poly;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=newnode;
}
void display(struct node* poly)
{
    while(poly!=NULL)
    {
        printf("%dx^%d",poly->coef,poly->exp);
        poly=poly->next;
        if(poly!=NULL)
        printf("+");
    }
    printf("\n");
}
struct node*addpoly(struct node*poly1,struct node*pol2)
{
    while(poly1!=NULL&&poly2!=NULL)
    {
        if(poly1->exp > poly2->exp)
        {
            insert(&result,poly1->coef,poly1->exp);
            poly1=poly1->next;
        }
        else if(poly1->exp < poly2->exp)
        {
            insert(&result,poly2->coef,poly2->exp);
            poly2=poly2->next;
        }
        else{
            insert(&result,poly1->coef+poly2->coef,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    while(poly1!=NULL)
    {
        poly1=poly1->next;
    }
    while(poly2!=NULL)
    {
        poly2=poly2->next;
    }
    return result;
}
int main()
{
    insert(&poly1, 5,2);
    insert(&poly1, 4,1);
    insert(&poly1,2,0);
    insert(&poly2,5,1);
    insert(&poly2,5,0);
    printf("\nPolynomial 1: ");
    display(poly1);
    printf("\nPolynomial 2:");
    display(poly2);
    struct node *sum=addpoly(poly1,poly2);
    printf("\nSum=");
    display(sum);
    return 0;
}