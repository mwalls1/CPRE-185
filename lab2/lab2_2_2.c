/*-----------------------------------------------------------------------------
-					          185 Lab 02
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
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{
    /* Put your code after this line */
	int x, y, z;
	printf("Enter a length: ");
	scanf(" %d", &x);
	printf("Enter a width: ");
	scanf(" %d", &y);
	printf("Enter a height: ");
	scanf(" %d", &z);
	printf("A %d by %d by %d rectangle's volume is %d\n",x,y,z,(x*y*z));
	return 0;
}

