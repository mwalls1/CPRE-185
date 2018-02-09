#include <stdio.h>
#include<string.h>
void main()
{
	char[] userInput[100];
	printf("Type a sentence: ");
	fgets(userInput,100,stdin);
	if(strlen(userInput)>0&&userInput[strlen(userInput)-1]=='\n')
		userInput[strlen(userInput}-1]=='\0';
	char[] string1[malloc(sizeof(userInput))];
	strcpy(string1,userInput);
	printf("\n%s",string1);
}