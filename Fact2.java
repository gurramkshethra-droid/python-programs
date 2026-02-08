import java.util.Scanner;
class Fact2
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
int n,i;
System.out.println("Enter the number ");
n=sc.nextInt();
int fact=1;
for(i=1; i<=n;i++)
fact=fact*i;
System.out.println("The factorial is "+fact);
}}