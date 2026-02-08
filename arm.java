import java.util.Scanner;
class Armstrong
{
public static void main(String[] args)
{
int n,temp,count=0,r;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the number: ");
n=sc.nextInt();
temp=n;
int num=0;
while(temp!=0)
{
count++;
temp=temp/10;
}
temp=n;
while(temp!=0)
{
r=temp%10;
num = num+Math.pow(r,count);
temp=temp/10;
}
if(n==num)
System.out.println(n+" is an Armstrong number");
else
System.out.println(n+" is not an Armstrong number");
}} 
