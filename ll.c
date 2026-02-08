#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL, *temp=NULL, *nn=NULL, *prev=NULL;
void sort() {
    struct node *i, *j;
    for( i=head; i!=NULL; i=i->next) {
        for(j=i->next; j!=NULL; j=j->next) {
            int t;
            if(i->data > j->data) {
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
}
int main() {
    int n;
    printf("enter n value");
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        nn=(struct node*)malloc(sizeof(struct node));
        printf("\n enter the data");
        scanf("%d",&nn->data);
        nn->next=NULL;
        if(head==NULL)
        head=temp=nn;
        else {
            temp->next=nn;
            temp=nn;
        }
    }
    temp=head;
    printf("\n the elements are");
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    struct node *i;
    struct node *j;
    int t;
    for( i=head; i!=NULL; i=i->next) {
        for(j=i->next; j!=NULL; j=j->next) {
            if(i->data > j->data) {
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
    int found=0;
    temp=head;
    int tt;
    printf("\n enter the search data");
    scanf("%d",&tt);
    int k=1;
    while(temp!=NULL) {
        if(temp->data==tt) {
            printf("%d found at %d", tt,k);
            found=1;
            break;
        }
        temp=temp->next;
        k++;
    }
    temp=head;
    printf(" \nafter task the elements are");
    while(temp!=NULL)
    {
        printf(" %d  ",temp->data);
        temp=temp->next;
    }
    
    return 0;
}