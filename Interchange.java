import java.util.*;

public class Interchange {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Main. */
        int n;
        Scanner s=new Scanner(System.in);
        n=s.nextInt();
        int a[][]=new int[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                a[i][j]=s.nextInt();
            }
        }
        int t=0;
        for(int i=0;i<n;i++) {
            t=a[i][i];
            a[i][i]=a[i][n-1-i];
            a[i][n-1-i]=t;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }
}