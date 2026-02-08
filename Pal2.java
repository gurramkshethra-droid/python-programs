import java.util.Scanner;
import java.io.*;
class Pal2
{
public static void main(String args[])
{
String str,rev="";
System.out.println("Enter the string ");
Scanner sc=new Scanner(System.in);
str=sc.next();
int length;
length=str.length();
for (int i=length-1; i>=0;i--)
{
rev=rev+str.charAt(i);
}
if(str.equalsIgnoreCase(rev))
System.out.println(str+ " is a palindrome string");
else
System.out.println(str+ " is not a palindrome  string");
}}