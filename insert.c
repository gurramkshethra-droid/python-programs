#include<stdio.h>
int main() {
    int i,j,key,a[10],n;
    printf("\n enter size of array");
    scanf("%d",&n);
    printf("\n enter array elements");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++) {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\n the insertion sort is");
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
}