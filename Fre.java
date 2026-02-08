import java.util.Scanner;
import java.io.*;
class Fre2
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the text ");
String text=sc.nextLine().toLowerCase();
String words[]=text.split(" ");
for(int i=0; i<words.length; i++)
{
String word=words[i];
if(word.equals("") )
continue;
int count=1;
for(int j=i+1; j<words.length; j++)
{
if(word.equals(words[j]))
{
count++;
words[j]="";
}
}
System.out.println("The frequency of "+word+" is "+count);
}
}}
