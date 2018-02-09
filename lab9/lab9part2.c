// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output
// up,left,down,right
// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS PROTOTYPE
int readWords(char* wl[MAXWORDS], char* filename); 
int getWord(int x, int y);
void addWord(char* word,int num,char* arr[MAXWORDS]);
void removeWord(char* arr[MAXWORDS],int num);
//modifies s to trim white space off the right side
// DO NOT MODIFY THIS PROTOTYPE
void trimws(char* s);
int main(int argc, char* argv[]) {
	// Do not modify this part. Write your code so that this works.
	char* wordlist[MAXWORDS];
	char* sentence[MAXWORDS];
	int wordCount;
	int numWords = 0;
	int i;
	int startY = 10;
	int startX = 16;
	wordCount = readWords(wordlist, argv[1]);
	initscr();
	refresh();
	int wordX =0;
	int wordY = 20;
	int x = 0;
	int y = 0;
	int up = 0;
	int left = 0;
	int down = 0;
	int right = 0;
	int bX = 0;
	int bS = 0;
	int bC = 0;
	int bT = 0;
	int over = 1;
	int tempUp = 0;
	int tempDown = 0;
	int tempLeft = 0;
	int tempRight = 0;
	int tempS = 0;
	int tempT = 0;
	int tempX = 0;
	int leftJoy = 0;
	int rightJoy = 0;
	int tempL = 0;
	int tempR = 0;
	int three, four, five, six, seven, eight;
	if (DEBUG) {
		for (i = 0; i< wordCount; i++) {
			mvprintw(y,x,"%15s",wordlist[i]);
			if(x<60)
				x+=15;
			else
			{
				x = 0;
				y++;
			}
		}
		printf("\n");
		}
	refresh();
	mvaddch(startY, startX,'#');
	refresh();
	do
	{
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",&bT,&bC,&bX,&bS,&rightJoy,&leftJoy,&three,&four,&five,&six,&seven,&eight,&up,&left,&down,&right);
		if(tempUp==0&&up==1&&startY>0)
		{
			mvaddch(startY, startX,' ');
			startY--;
		}
		if(tempDown==0&&down==1&&startY<15)
		{
			if(startX>16&&startY>13)
			{
			}
			else
			{
			mvaddch(startY, startX,' ');
			startY++;
			}
		}
		if(tempLeft==0&&left==1&&startX>16)
		{
			mvaddch(startY, startX,' ');
			startX-=15;
		}
		if(tempRight==0&&right==1&&startX<75)
		{
			if(startY>14)
			{
			}
			else{
			mvaddch(startY, startX,' ');
			startX+=15;
			}
		}
		if(tempS==0&&bS==1)
		{
			addWord(wordlist[getWord(startX,startY)],numWords,sentence);
			numWords++;
			mvprintw(wordY,wordX,"%s",sentence[numWords-1]);
			wordX+=strlen(sentence[numWords-1]);
		}
		if(tempT==0&&bT==1)
		{
			char a[WORDLEN+2] = " ";
			addWord(strcat(a,wordlist[getWord(startX,startY)]),numWords,sentence);
			numWords++;
			mvprintw(wordY,wordX,"%s",sentence[numWords-1]);
			wordX+=strlen(sentence[numWords-1]);
		}
		if(tempX==0&&bX==1&&numWords>0)
		{
			removeWord(sentence,numWords);
			numWords--;
			wordX-=strlen(sentence[numWords]);
			mvprintw(wordY,wordX,"               ");
		}
		if(rightJoy ==1&&tempR == 0)
		{
			numWords = 0;
			int i = 0;
			for(i = 0; i < MAXWORDS; i ++)
			{
				sentence[i] = NULL;
				
			}
			wordX = 0;
			mvprintw(wordY,wordX,"                                                                                                             ");
		}
		tempL = leftJoy;
		tempR = rightJoy;
		tempX = bX;
		tempT = bT;
		tempS = bS;
		tempRight = right;
		tempLeft = left;
		tempUp = up;
		tempDown = down;
		mvaddch(startY, startX,'#');
		refresh();
	}
	while(over==1);
	while(1)
	{}
	endwin();
// Your code goes here. Don't forget to include the ncurses library 
    return 0;
	}

// Modify this function so it trims the white space 
// off the right side of string s
void trimws(char* s) {
	int i = strlen(s)-1;
	int done = 0;
	while(done==0&&i>-1)
	{
		if(!isspace(s[i]))
			done = 1;
		else
			s[i]='\0';
		i--;
	}
	
}


// Modify this function so it reads words from the file
// into wl and trims the whitespace off of the end
int readWords(char* wl[MAXWORDS], char* filename) {
	int i = 0;
	int j = 0;
	FILE *fp = fopen(filename,"r");
	char* line;
	while(!feof(fp))
	{
		line = malloc(sizeof(char)*WORDLEN);
		fgets(line,WORDLEN,fp);
		trimws(line);
		wl[i] = line;
		if(strlen(line)==0)
		{
			i--;
			j--;
		}
		i++;
		j++;
	}
	fclose(fp);
	return j;
}
int getWord(int x, int y)
{
	return y*5+(x-1)/15-1;
}
void addWord(char* word,int num,char* arr[MAXWORDS])
{
	arr[num] = malloc(sizeof(char)*(strlen(word)+2));
	strcpy(arr[num],word);
}
void removeWord(char* arr[MAXWORDS],int num)
{
	arr[num] = NULL;
}