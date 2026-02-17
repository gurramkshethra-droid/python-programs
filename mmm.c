#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d",&n);
    int a[n];
    double sum=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }   
    double mean=sum/n;
    double median;
    if(n%2==0) {
        median=(a[(n/2)-1]+a[n/2])/2.0;
    }
    else {
        median=a[n/2];
    }
    int maxc=1,count=1,mode=a[0],i;
    for(i=1;i<n;i++) {
        if(a[i]==a[i-1]) {
            count++;
        } else {
            if(maxc<count) {
                maxc=count;
                mode=a[i-1];
            }
            count=1;
        }
    }
    if(count>maxc) {
        mode=a[n-1];
    }
    printf("%.2f %.2f %d",mean,median,mode);
    return 0;
}