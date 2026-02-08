import java.util.Scanner;
class Rev2
{
public static void main(String args[]) {
Scanner sc=new Scanner(System.in);
int num,rev=0;
System.out.println("Enter the number");
num=sc.nextInt();
int t;
t=num;
while(t!=0)
{
int r=t%10;
rev=(rev*10)+r;
t=t/10;
}
System.out.println("The reverse is: " +rev);
}}