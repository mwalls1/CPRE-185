/*-----------------------------------------------------------------------------
-					          185 Lab 02
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>


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
    int integerResult;
    double decimalResult;

    integerResult = 77 / 5;
    printf("The value of 77/5 is %lf, using integer math\n", integerResult);

	
	
    integerResult = 2 + 3;
	//Tried to print integer, but forgot to add the variable integerResult in the print statement
    printf("The value of 2+3 is %d\n",integerResult);
	
	
	
    decimalResult = 1.0 / 22.0;
	//Tried to print double with %d tag, should be %lf
    printf("The value 1.0/22.0 is %lf\n", decimalResult);

    return 0;
}

