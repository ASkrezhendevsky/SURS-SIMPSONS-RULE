#include <stdio.h>
#include<math.h>
 
double f(double x)
{
	return sin(x*x+2*x);	
}
 
int main() {
	float a, b, eps;
	
	printf("Enter a, b, eps");
	scanf("%f%f%f",&a,&b,&eps);
	
	float I = eps+1, I1 =0;
	int N;
	int i;
	for (N = 2; (N<=4)||(fabs(I1-I)>eps); N*=2)
	{
		float h, sum2=0, sum4=0, sum=0;
		h = (b-a)/(2*N);
		for (i = 1; i<=2*N-1; i+=2)
		{   
			sum4+=f(a+h*i);
			sum2+=f(a+h*(i+1));
		}
		sum=f(a)+4*sum4+2*sum2-f(b);
		I=I1;
		I1=(h/3)*sum;
	}
	printf("Result = %f",I1);
	return 0;
}
