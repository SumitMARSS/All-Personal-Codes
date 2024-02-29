#include<stdio.h>
#include<math.h>
int multiple(int n)//just to declare user function
{
        int i,fact=1;
        for(i=1;i<=n;i++)
                fact=fact*i;
        return fact;
}
int main()
{
        double x, sinx=0, z, term;
    int j, n=5, i,t=-1;

        printf("\nEnter the value for x : ") ;  //taking inputs
        scanf("%lf", &x) ;
        x = x * 3.14159 / 180 ;   //converting degree to radian
    i=0;
    z=sin(x);
        for(i=1;i<=n;i=i+2)//logics
    {
        t=-t;
        term=t*pow(x,i)/multiple(i);
        sinx=sinx+term;
    }

        printf("\nsin(x) is approximately %.6f\n", sinx);//printing the result
    return 0;
}
