#include<stdio.h>
void qsort(int a[],int low,int high);
int part(int a[],int low,int high);

int main() {
    int a[10],i, n;
    printf("\n enter size of array");
    scanf("%d",&n);
    printf("\n enter array elements");
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    qsort(a,0,n-1);
    printf("\n the quick sort is");
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    return 0;
}
void qsort(int a[],int low,int high) {
    if(low<high) {
        int p=part(a,low,high);
        qsort(a,low,p-1);
        qsort(a,p+1,high);
    }
}
int part(int a[],int low,int high) {
    int pivot=a[low];
    int i=low+1,j=high,t;
    while(i<=j)
    {
        if(a[i]<pivot)
        {
            i++;
        }
        else if(a[j]>pivot)
        {
            j--;
        }
        else
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[low];
    a[low]=a[j];
    a[j]=t;
    return j;
}

