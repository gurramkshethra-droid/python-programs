#include<stdio.h>
#include<string.h>
int main() {
  char str[20], c[20];
  int l;
  printf("enter the first string");
  scanf("%s",str);
  l=strlen(str);
  for(int i=l-1,j=0; i>=0; i--,j++) {
    c[j]=str[i];
  }
  c[l]='\0';
  if((strcmp(str,c))==0)
  printf("\n %s is a palindrome number",str);
  else
  printf("\n %s is not a palindrome number",str);
  return 0;
}