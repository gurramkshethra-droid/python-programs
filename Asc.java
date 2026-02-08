import java.util.Scanner;
class Asc
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
int n;
System.out.println("Enter the no.of names");
n=sc.nextInt();
String str[]=new String[n];
System.out.println("Enter the names ");
for(int i=0;i<n;i++)
{
str[i]=sc.next();
}
String temp;
for(int i=0; i<n; i++)
{
for(int j=i+1; j<n; j++)
{
if((str[i].compareTo(str[j]))>0)
{
temp=str[i];
str[i]=str[j];
str[j]=temp;
}
}
}
System.out.println("The sorted names are :");
for(int i=0; i<n;i++)
System.out.print(str[i]+ "  ");
}}
