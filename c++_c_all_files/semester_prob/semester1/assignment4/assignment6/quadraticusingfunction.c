#include<stdio.h>
#include<math.h>
void condition();//just to declare user function
int main()
{
    int a,b,c,D;//defining value
    printf("Enter the coeff of x^2,x,constant term\n");
    scanf("%d\n%d\n%d",&a,&b,&c);//taking input
    D=b*b-4*a*c;//calculating discriminant
    condition(a,b,c,D);//user defined function calling
return 0;
}

void condition(int a,int b,int c,int D)//defining user defined function
{float x,y;
if (a!=0 && b!=0)//condition if a,b is not equal to 0
{
if (D<0)//discriminant is less than 0
{
    printf("Both roots are imaginary,no real roots");//printing the result
}
else if (D==0)//discriminant is equal to 0
{
    printf("Both roots are equal\n");
    x=-(float)b/(2*a);//formula for finding roots
    printf("Roots is %f",x);//printing the result
}
else
{
    printf("Roots are real and distinct\n");
    x=(-b+sqrt(D))/(2*a);//formula for finding roots
    y=(-b-sqrt(D))/(2*a);//formula for finding roots
    printf("\nRoots are:%f,%f",x,y);//printing the result
}
}
else if (a==0 && b==0)
{
    printf("No roots are possible");//printing the result
}
else if (a==0)
{
    printf("Only one root is possible\n");//printing the result
    x=-(float)c/b;
    printf("Roots is %f",x);//printing the result
}}