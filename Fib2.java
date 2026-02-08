import java.util.Scanner;
class Fib2
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
int t1=0,t2=1,t3,i;
System.out.println("Enter no.of elements");
int n=sc.nextInt();
System.out.println("The Fibonacci series is :");
for(i=0;i<n;i++)
{
System.out.print(t1+"  ");
t3=t1+t2;
t1=t2;
t2=t3;
}
}}