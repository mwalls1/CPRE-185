#include <stdio.h>
#include <math.h>
int isValidISBN(int arr[]);
void scanISBN(int arr[]);
int main()
{
	int numBooks;
	scanf(" %d", &numBooks);
	printf("%d\n",numBooks);
	int book[10];
	int i;
	int j;
	for(i = 0; i < numBooks; i ++)
	{
		scanISBN(book);
		if(isValidISBN(book))
		{
			for(j = 0; j<10; j++)
				printf("%d",book[j]);
			printf("\n");
		}
	}
}
void scanISBN(int arr[])
{
	int i;
	for(i = 0; i<10; i ++)
	{
		scanf("%1d", &arr[i]);
	}
	/*for(i = 0; i<10; i ++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");*/
}
int isValidISBN(int arr[])
{
	int i;
	int validInt = 0;
	int index = 10;
	for(i=0; i < 10; i++)
	{
		//printf("%d\n",index);
		validInt = validInt+index*arr[i];
		//printf("%d\n",validInt);
		index=index-1;
	}
	//printf("%d\n",validInt);
	if((validInt%11)==0)
		return 1;
	else
		return 0;
}