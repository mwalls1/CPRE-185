// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C)
{
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d",time,g_x, g_y, g_z, Button_T, Button_X, Button_C, Button_S);
	if(*Button_S==1)
		return 1;
	else
		return 0;
}
// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);
double roll(double x_mag)
{
	if(x_mag>1)
		x_mag = 1;
	if(x_mag<-1)
		x_mag = -1;
	return asin(x_mag);
}

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);
double pitch(double y_mag)
{
	if(y_mag>1)
		y_mag = 1;
	if(y_mag<-1)
		y_mag = -1;
	return asin(y_mag);
}


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);
int scaleRadsForScreen(double rad)
{
	return rad*(39/(PI/2.0));
}
// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);
void print_chars(int num, char use)
{
	for(int i = 0; i < num; i ++)
		printf("%c",use);
}
//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);
void graph_line(int number)
{
	if(number<0)
	{
		print_chars((40+number),' ');
		print_chars(abs(number),'L');
	}
	if(number>0)
	{
		print_chars(39,' ');
		print_chars(number,'R');
	}
	if(number==0)
	{
		print_chars(39,' ');
		print_chars(1,'0');
	}
	print_chars(1,'\n');
}
int main()
{
	double x, y, z;                             // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;    // variables to hold the button statuses
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int scaled_value;                           // value of the roll adjusted to fit screen display
	int t;
	//insert any beginning needed code here
	int whatToCalc = 0;
	int button = 0;
	do
	{
		// Get line of input
		read_line(&x,&y,&z,&t,&b_Triangle, &b_X, &b_Square, &b_Circle);
		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
		if(button == 0&&b_Triangle == 1&&whatToCalc == 0)
		{
			whatToCalc = 1;
			button = 1;
		}
		if(button==0&&b_Triangle == 1&&whatToCalc == 1)
		{
			whatToCalc = 0;
			button = 1;
		}
		if(whatToCalc == 0)
		{
			roll_rad = roll(x);
			scaled_value = scaleRadsForScreen(roll_rad);
		}
		if(whatToCalc == 1)
		{
			pitch_rad = pitch(y);
			scaled_value = scaleRadsForScreen(pitch_rad);
		}
		button = b_Triangle;
		// switch between roll and pitch(up vs. down button)
		// Scale your output value
		// Output your graph line
		graph_line(-scaled_value);
		fflush(stdout);
	} while (b_Square == 0); // Modify to stop when the square button is pressed
	return 0;
}
