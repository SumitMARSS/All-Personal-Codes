#include <stdio.h>
int func();
int main()
{
    int a=5,b=3,choice;
    
    /*//case 1:          //if we are using case 1 then it doesn't recognize sum variable
        func(a,b);               //shows that auto is a local variable
        printf("%d",sum);*/
    //case 2:
        int sum=func(a,b);// we have to define the variable sum as a new variable
        printf("The sum is %d",sum);
}
int func(int a, int b)
{
    /*when we are using any variable it is defined only under that 
    given function like sum is defined in func function only.*/
    auto int sum;//a variable defined without any storage class spacification by default an automatic variable
    sum=a+b;
    return sum;
}