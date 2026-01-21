#include<stdio.h>
int main() {
    int i, j, min, a[10], n, t;
    printf("\n enter size of array");
    scanf("%d",&n);
    printf("\n enter array elements");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
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
    printf("\n the selection sort is");
    for(i=0;i<n;i++) {
        printf("%d ", a[i]);
    }
}