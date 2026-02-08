import java.util.Scanner;
class Prime2
{
public static void main(String args[])
{
int n,i;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the number ");
n=sc.nextInt();
int count=0;
System.out.println("The prime numbers are  :");
for(i=2;i<n;i++)
{
count=0;
for(int j=1;j<=i;j++)
{
if(i%j==0)
count++;
}
if(count==2)
System.out.println(i+ " ");
}
}}
