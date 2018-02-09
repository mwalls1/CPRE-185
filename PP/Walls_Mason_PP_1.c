/*      Mason Walls

        walls594@iastate.edu

        CPRE 185 Section G

Programming Practice NUMBER 1

         <Reflection 1 What were you trying to learn or achieve?>

                My goal for this program was for a user to be able to easily use the quadratic formula to calculate X values for when f(x)=0. I was trying to learn how if I write this program in a way that we havent been doing in class to see if it still works. *(it does)
			

        <Reflection 2 Were you successful? Why or Why not?>

				I was succesful in doing this. I believe I was succesful because I have a lot of knowledge in programming in Java from past experience which is very similar to c. The in class work also helped for the main framework of the program such as imported libraris and making functions which is a little different than what ive learned in the past.

		<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>

				If i were to start this program over, I would wright it in mor the fashion that we have learned. I made the main function only one line to rely on the other functions I wrote to do the bulk of the work. It worked well but made things a little tedious in the end.

		<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>

				The most important thing I learned is that parenthesis can get overwhelming and that there are infinite amount of ways to wright a program. This is important because as an engineer it is important to write a program with as little wasted memory as possible to keep things running at there best. Also, that usually makes the code easier to understand.

		<Other questions/comments for Instructors>

*/



#include <stdio.h>
#include <math.h>
double posX(double a, double b, double c);
double negX(double a, double b, double c);
void printer(double a, double b);
int runCode();
int main(void)
{
	return runCode();
}
double posX(double a, double b, double c)
{
	return ((-b+(sqrt((pow(b,2)-(4*a*c)))))/(2*a));
}
double negX(double a, double b, double c)
{
	return ((-b-(sqrt((pow(b,2)-(4*a*c)))))/(2*a));
}
int runCode()
{
	double a,b,c,pX,nX;
	printf("Enter the 'a' value of your quadratic: ");
	scanf(" %lf",&a);
	printf("Enter the 'b' value of your quadratic: ");
	scanf(" %lf",&b);
	printf("Enter the 'c' value of your quadratic: ");
	scanf(" %lf",&c);
	pX = posX(a,b,c);
	nX = negX(a,b,c);
	printer(pX,nX);
	return 0;
}
void printer(double a, double b)
{
	if(a<b)
		printf("The values of x when your funtcion equals 0 are: x = %lf and x = %lf",a,b);
	else
		printf("The values of x when your funtcion equals 0 are: x = %lf and x = %lf",b,a);
}


