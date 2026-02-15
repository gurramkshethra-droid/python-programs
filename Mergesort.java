import java.util.Scanner;
public class Mergesort {
    public static void merge(int a[],int left,int right) {
        if(left<right) {
            int mid=left+(right-left)/2;
            merge(a,left,mid);
            merge(a,mid+1,right);
            mergesorts(a,left,mid,right);
        }
    }
    public static void mergesorts(int a[],int left,int mid,int right) {
        int n1,n2;
        n1=mid-left+1;
        n2=right-mid;
        int[] l=new int[n1];
        int[] r=new int[n2];
        for(int i=0;i<n1;i++) {
            l[i]=a[left+i];
        }
        for(int i=0;i<n2;i++) {
            r[i]=a[mid+1+i];
        }
        int i=0,j=0,k=left;
        while(i<n1 && j<n2) {
            if(l[i]<=r[j]) {
                a[k]=l[i];
                i++;
                k++;
            }
            else {
                a[k]=r[j];
                j++;
                k++;
            }
        }
        while(i<n1) {
            a[k]=l[i];
            i++;
            k++;
        }
        while(j<n2) {
            a[k]=r[j];
            j++;
            k++;
        }
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.print("Enter size");
        int n;
        n=s.nextInt();
        int[] a=new int[n];
        System.out.println("Enter elements");
        for(int i=0;i<n;i++) {
            a[i]=s.nextInt();
        }
        merge(a,0,n-1);
        System.out.println("After sorting");
        for(int i=0;i<n;i++) {
            System.out.print(a[i]+" ");
        }
    }
}