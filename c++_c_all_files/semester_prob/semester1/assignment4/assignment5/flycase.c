#include <stdio.h>
int main()
//defining terms
{int a,c=0;
char ch,x;
//using loops to repeating our questions
while (1)//1 is used for loops to continue until infinite
{
    //getting values
    printf("Enter the value of a\n");
    scanf("%d",&a);
    //adding the terms by initialising value of c
    c=c+a;
    //printing result
    printf("The sum of given number is %d\n",c);
    //giving conditions if we have to proceed or not
    printf("Enter another number for addition \n if you don't want to continue write x\n",a);
    //taking inputs if we have to proceed or not
    scanf("%c",&ch);
    //logic to exit the loop
    if (ch=='x')
    {
        break;
    }    
}
return 0;
}