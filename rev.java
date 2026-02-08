import java.util.Scanner;
class Reverse
{
public static void main(String[] args)
{
int r,rev=0,temp,n;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the number: ");
n=sc.nextInt();
temp=n;
while(temp!=0)
{
r=temp%10;
rev=(rev*10)+r;
temp=temp/10;
}
System.out.println(rev+" is the reverse of "+n);
}
}
