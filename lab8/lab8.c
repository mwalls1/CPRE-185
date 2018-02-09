// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch
// Updated for CprE 185, 2017 Daniels


// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 100
#define NUMROWS 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);
void generate_maze(int difficulty)
{
	int i = 0;
	int j = 0;
	int random;
	for(i = 0; i < NUMROWS; i++)
	{
		for(j = 0; j < NUMCOLS; j++)
		{
			random = rand()%100;
			if(random>0&&random<=difficulty)
				MAZE[i][j] = '*';
			else
				MAZE[i][j] = ' ';
		}
	}
	
}

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);
void draw_maze(void)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < NUMROWS; i++)
	{
		for(j = 0; j < NUMCOLS; j++)
		{
			mvaddch(i,j,MAZE[i][j]);
		}
	}
}

// PRE: -1.0 < x_mag < 1.0
// POST: Returns either -1, 0, or 1 depending on which way to turn or fall straight down.
// You may want to reuse the roll function written in previous labs.  
double calc_roll(float x_mag);
double calc_roll(float x_mag)
{
	if(x_mag>1)
			x_mag = 1;
		if(x_mag<-1)
			x_mag = -1;
	return asin(x_mag);
}
/*
This is the function you should use to print.

mvaddch(int y, int x, char c)

y and x are the position to print at.
c is the charcater to print. 
*/

// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN
void main(int argc, char* argv[])
{
	int startX = NUMCOLS/2;
	int startY = 0;
	srand(time(NULL));
	// setup screen    
	initscr();
	refresh();
    int time;
	int time1 = 0;
	int gameOver = 0;
	double x, y, z;
	// Generate and draw the maze, with initial avatar
    generate_maze(atoi(argv[1]));
	draw_maze();
	mvaddch(0,NUMCOLS/2,AVATAR);
	refresh();
	// Event loop
	do
	{
    
		// Read data
		scanf("%d, %lf, %lf, %lf",&time,&x,&y,&z);
		if(MAZE[startY+1][startX]==WALL&&MAZE[startY][startX+1]==WALL&&MAZE[startY][startX-1]==WALL)
		{
			gameOver = 1;
		}
		else if(time-time1>=450&&time-time1<=550&&calc_roll(x)>=.6)
		{
			time1 = time;
			if(MAZE[startY][startX-1]!=WALL)
			{
				mvaddch(startY, startX,' ');
				startX--;
			}
			if(MAZE[startY+1][startX]!='*')
			{
				mvaddch(startY, startX,' ');
				startY++;
			}
			mvaddch(startY, startX,AVATAR);
			mvaddch(startY-1, startX+1,' ');
		}
		else if(time-time1>=450&&time-time1<=550&&calc_roll(x)<=-.6)
		{
			if(MAZE[startY][startX+1]!='*')
			{
				mvaddch(startY, startX,' ');
				startX++;
			}
			if(MAZE[startY+1][startX]!='*')
			{
				mvaddch(startY, startX,' ');
				startY++;
			}
			time1 = time;
			mvaddch(startY, startX,AVATAR);
			mvaddch(startY-1, startX-1,' ');
		}
		else if(time-time1>=450&&time-time1<=550)
		{
			if(MAZE[startY+1][startX]!='*')
			{
				mvaddch(startY, startX,' ');
				startY++;
			}
			time1 = time;
			mvaddch(startY, startX,AVATAR);
			mvaddch(startY-1, startX,' ');
		}
		refresh();'
		if(startY==NUMROWS-1)
			gameOver=2;
	} while(gameOver==0); // Change this to end game at right time 

	// Print the win message
	endwin();
	if(gameOver==1)
		printf("You lose");
	else
		printf("YOU WIN!\n");
}



