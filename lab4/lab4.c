/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int close_to(double tol, double point,double value);
double mag(double a, double b, double c);
int getFace(double mag, double gx, double gy,double gz);
int main(void)
{
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	double magnitude;
	int face;
	int lastValue = 0;
    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &ax, &ay, &az, &b1, &b2, &b3, &b4 );
		if(b1==1)
			return 0;
        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */
		magnitude = mag(ax,ay,az);
		face = getFace(magnitude,ax,ay,az);
		//printf("%lf, %d\n",magnitude,face);
		if(face==1&&lastValue!=face)
		{
			printf("TOP\n");
			lastValue = 1;
		}
		if(face==2&&lastValue!=face)
		{
			printf("BOTTOM\n");
			lastValue = 2;
		}
		if(face==3&&lastValue!=face)
		{
			printf("LEFT\n");
			lastValue = 3;
		}
		if(face==4&&lastValue!=face)
		{
			printf("RIGHT\n");
			lastValue = 4;
		}
		if(face==5&&lastValue!=face)
		{
			printf("FRONT\n");
			lastValue = 5;
		}
		if(face==6&&lastValue!=face)
		{
			printf("BACK\n");
			lastValue = 6;
		}
		fflush(stdout);
        //printf("", t, mag(ax, ay, az));

    }

    return 0;
}


/* Put your functions here */
int close_to(double tol, double point,double value)
{
	if((value>=(point-tol))&&(value<=(point+tol)))
		return 1;
	else
		return 0;
}
double mag(double a, double b, double c)
{
	return sqrt(pow(a,2)+pow(b,2)+pow(c,2));
}
int getFace(double mag, double gx, double gy, double gz)
{
	if(close_to(.2,1,mag))
	{
		if(close_to(.05,1,gy))
			return 1;
		else if(close_to(.05,-1,gy))
			return 2;
		else if(close_to(.05,-1,gx))
			return 3;
		else if(close_to(.05,1,gx))
			return 4;
		else if(close_to(.05,-1,gz))
			return 5;
		else if(close_to(.05,1,gz))
			return 6;
		else
			return 7;	
	}
}