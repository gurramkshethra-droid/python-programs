#include<stdio.h>
void sort(int a[], int n);
int bsearch(int a[], int low,int high,int key);
int main()
{
    int a[10],n,i,found=-1,key;
    printf("\n enter size of array");
    scanf("%d",&n);
    printf("\n enter array elements");
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    printf("\n enter key element from above array");
    scanf("%d",&key);
    sort(a,n);
    found=bsearch(a,0,n-1,key);
    if(found==-1)
    printf("element not found");
    else
    printf("%d found at %d",key,found);
}
void sort(int a[], int n)
{
    int i,j,min,t;
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++) {
            if(a[j]<a[min]) {
                min=j;
            }
        }
        if(i!=min) {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
}
int bsearch(int a[], int low, int high,int key)
{
    while(low<=high)
    {
        int mid;
        mid=(low+high)/2;
        if(key==a[mid])
        return mid;
        else if(key<a[mid])
        return bsearch(a,low,mid-1,key);
        else
        return bsearch(a,mid+1,high,key);
    }
    return -1;
}
