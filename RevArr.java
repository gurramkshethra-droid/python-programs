import java.util.Scanner;
class RevArr
{
public static void main(String args[])
{
int a[]=new int[30];
int temp;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the no.of elements");
int n=sc.nextInt();
System.out.println("Enter the elements in array");
for(int i=0;i<n;i++)
{
System.out.print("a["+i+"]=");
a[i]=sc.nextInt();
System.out.println();
}
for(int i=0;i<n/2;i++)
{
temp=a[i];
a[i]=a[n-i-1];
a[n-i-1]=temp;
}
System.out.println("After reversing the array is ");
for(int i=0;i<n; i++)
{
System.out.println(" "+a[i]);
}
}}