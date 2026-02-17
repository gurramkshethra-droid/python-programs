#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }  
    int nz=0,np=0,nn=0;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            nz++;
        }
        else if(a[i]>0) {
            np++;
        }
        else {
            nn++;
        }
    }
    printf("%d %d %d",nz,np,nn);
    return 0;
}