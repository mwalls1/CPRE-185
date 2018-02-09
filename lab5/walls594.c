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
double meters(double t);
double mag(double a, double b, double c);
int isFalling(double mag, int t);
int doneFalling =0;
int isFall = 0;
int tFall;
int tFell;
int main(void)
{
	printf("<Mason> <Walls>\n<910333448>\n");
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	double magnitude;
	int readData = 0;
	int printedWait = 0;
	int printedFall = 0;
	double time0, time1, time2;
	double v1,x1,x2;
	double x0 = 0;
	double v0 = 0;
	int finish = 0;
	int t0 = 0;
	double dist;
	time0=0;
    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &ax, &ay, &az, &b1, &b2, &b3, &b4 );
		magnitude = mag(gx,gy,gz);
		isFalling(magnitude, t);
		if(!readData)
		{
			printf("Ok, I'm now receiving data.\n");
			readData = 1;
		}
		if(b1==1)
			return 0;
		if(!printedWait)
		{
			printf("I'm Waiting");
			printedWait  =1;
		}
		if(!isFall&&printedWait&&(t-t0)>=950&&(t-t0)<=1050&&!finish)
		{
			printf(".");
			t0 = t;
		}
		if(isFall&&!printedFall)
		{
			
			tFall = t;
			printf("\n\t\tHelp me! I'm Falling");
			printedFall = 1;
			time0=t/1000.0;
		}
		if(isFall&&printedFall&&(t-t0)>=950&&(t-t0)<=1050&&!finish)
		{
			printf("!");
			t0 = t;
		}
		if(isFall)
		{
			//printf("\nm: %lf v: %lf x: %lf",1-(mag(gx,gy,gz)),v1,x1);
			time1=t/1000.0;
			v1 = (v0+(9.8*(1-(mag(gx,gy,gz)))*(time1-time0)));
			v0 = v1;
			x1 = x0+v1*(time1-time0);
			x0=x1;
			time0=time1;
		}
		if(printedWait&&printedFall&&doneFalling&&!finish)
		{
			tFell = t;
			dist = meters((tFell-tFall)/1000.0);
			printf("\n\t\t\t\tOuch! I fell %lf meters in %lf seconds.",dist,(tFell-tFall)/1000.0);
			printf("\nCompensating for air resistance, the fall was %lf meters.", x1);
			printf("\nThis is a %lf%% difference than computed before",((dist-x0)/dist)*100);
			finish = 1;
			return 0;
		}
		fflush(stdout);
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
	return sqrt(((pow(a,2))+(pow(b,2))+(pow(c,2))));
}
int isFalling(double mag, int t)
{
	if(close_to(.5,0,mag))
	{
		isFall = 1;
		return 1;
	}
	else if(isFall&&mag>1)
	{
		isFall = 0;
		doneFalling = 1;
		return 0;
	}
}
double meters(double t)
{
	return ((1/2.0)*(9.8)*pow(t,2));
}