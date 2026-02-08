import java.util.Scanner;
class Prime2
{
public static void main(String[] args)
{
int n,found;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the number");
n=sc.nextInt();
System.out.println("the prime numbers upto "+n+ " are:");
for(int i=2;i<=n;i++)
{
found=1;
for(int j=2;j<i;j++)
{
if(i%j==0)
found=0;
}
if(found!=0)
System.out.print(i+" ");
}}
}
