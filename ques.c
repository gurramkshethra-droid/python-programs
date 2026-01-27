#include<stdio.h>
void main()
{
	FILE *fp,*fcaps,*fsmall;
	char ch;
	fp=fopen("x.txt","w+");
	printf("enter text\n");
	while((ch=getchar())!='\n')
	putc(ch,fp);
	fclose(fp);

	fp=fopen("x.txt","r");
	fcaps=fopen("caps.txt","w");
	fsmall=fopen("small.txt","w");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch>='A'&&ch<='Z')
		fputc(ch,fcaps);
		else
		fputc(ch,fsmall);
	}
	fclose(fp);
	fclose(fcaps);
	fclose(fsmall);
	fcaps=fopen("caps.txt","r");
	printf("Capital Letters Are \n");
	while((ch=fgetc(fcaps))!=EOF)
	printf("%c",ch);
	fclose(fcaps);
	fsmall=fopen("small.txt","r");
	printf("\n Small Letters Are \n");
	while((ch=fgetc(fsmall))!=EOF)
	printf("%c",ch);
	fclose(fsmall);
} //copying frm one file to another file