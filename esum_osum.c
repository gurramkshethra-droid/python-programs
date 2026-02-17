#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }  
    int esum=0,osum=0;
    for(int i=0;i<n;i++) {
        if(a[i]%2==0) {
            esum+=a[i];
        }
        else {
            osum+=a[i];
        }
    }
    printf("%d %d",osum,esum);
    return 0;
}