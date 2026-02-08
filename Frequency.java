import java.util.Scanner;
import java.util.*;
class Frequency
{
public static void main(String args[])
{
int count=0;
String text;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the text: ");
text=sc.nextLine();
String text1=text.toLowerCase();
String words[]=text1.split(" ");
for(int i=0;i<words.length;i++)
{
if(words[i].equals(""))
{
continue;
}
count=1;
for(int j=i+1; j<words.length; j++)
{
if(words[i].equals(words[j]))
{
count++;
words[j]="";
}
}
System.out.println("The frequency of "+words[i]+" is = "+count);
}
}
}