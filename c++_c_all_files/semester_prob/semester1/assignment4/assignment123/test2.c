#include <stdio.h>
int main()
{int number;
printf("Enter the number of the subject\n");
scanf("%d",&number);
if (number<41)
{
    printf("Grade is F");
}
else if (number<51)
{
    printf("Grade is D");
}
else if (number<61)
{
    printf("Grade is C");
}
else if (number<71)
{
    printf("Grade is B");
}
else if (number<81)
{
    printf("Grade is A");
}
else if (number<91)
{
    printf("Grade is E");
}
else if (number<101)
{
    printf("Grade is O");
}
else
{
    printf("Error in entry");
}
return 0;
}