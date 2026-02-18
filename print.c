#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,m;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }   
    scanf("%d",&m);
    int b[100];
    for(int i=0;i<m;i++) {
        scanf("%d",&b[i]);
    } 
    for(int i=0;i<m;i++) {
        if(b[i]>=0 && b[i]<n) {
            printf("%d",a[b[i]]);
        }
        else {
            printf("-1");
        }
        if(i!=m-1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}