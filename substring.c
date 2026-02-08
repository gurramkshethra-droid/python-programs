#include<stdio.h>
#include<string.h>
int main() {
  char str[20], c[20];
  int pos,l1,l2;
  printf("\n enter main string");
  scanf("%s",str);
  printf("\n enter substring ");
  scanf("%s",c);
  printf("\n enter position to enter substring");
  scanf("%d",&pos);
  l1=strlen(str);
  l2=strlen(c);
  for(int i=l1;i>=pos; i++) {
    str[i+l2]=str[i];
  }
  for(int i=0; i<l2; i++) {
    str[i+pos]=c[i];
  }
  printf("\n after inserting the substring is %s",str);
  return 0;
}