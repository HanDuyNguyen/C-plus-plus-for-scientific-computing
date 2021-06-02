/* Program: Finding real roots of nonlinear equation using Fixed Point Iteration
   Author: Han Nguyen
   Date: June 2, 2021 */

/* Header Files */
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
using namespace std;

/* Define function f(x) which is to be solved */
float   f(float x){   
    return cos(x)-3*x+1;
}
/* Write f(x) as x = g(x) and define g(x) here */
float   g(float x){
    return (1+cos(x))/3;
}  

int main()
{
	 int step=1, N = 0;
	 float x0 = 0, x1 = 0, e = 0;

	/* Setting precision and writing floating point values in fixed-point notation. */
	 cout<< setprecision(6)<<fixed;
	 
	 /* Inputs */
	 cout<<"Enter initial guess: ";
	 cin>>x0;

	 cout<<"Enter tolerable error: ";
	 cin>>e;

	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 /* Implementing Fixed Point Iteration */
	 cout<< endl<<"**************************"<< endl;
	 cout<<"Fixed Point Iteration Method"<< endl;
	 cout<<"**************************"<< endl;
	 do
	 {
		  x1 = g(x0);
		  cout<<"Iteration-"<< step<<":\t x1 = "<< setw(10)<< x1<<" and f(x1) = "<< setw(10)<< f(x1)<< endl;

		  step = step + 1;

		  if(step>N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }

		  x0 = x1;

	 }while( fabs(f(x1)) > e);

	 cout<< endl<<"Root is "<< x1 << endl;
	 cout<< "Number of iterations is "<< step;

	 return(0);
}
