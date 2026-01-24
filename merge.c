#include<stdio.h>
int main(int argc,char *argv[])
{
	FILE *fp,*fp1;
	char text[20],ch;
	fp=fopen(argv[1],"w");
	printf("Enter text");
	scanf("%s",text);
	fprintf(fp,"%s",text);
	fclose(fp);
	fp1=fopen(argv[2],"w");
	printf("Enter text");
	scanf("%s",text);
	fprintf(fp1,"%s",text);
	fclose(fp1);
    fp=fopen(argv[1],"r");
   fp1=fopen(argv[2],"a");
	while((ch=fgetc(fp))!=EOF)
	fputc(ch,fp1);
	fclose(fp);
	fclose(fp1);
	return 0;
}