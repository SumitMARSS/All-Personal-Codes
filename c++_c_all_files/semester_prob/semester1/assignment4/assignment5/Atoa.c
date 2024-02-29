#include <stdio.h>
char main()
{
//defining inputs
char ch;
//taking input
printf("Enter the character \n");
scanf("%c",& ch);
//logics for capital letter to small letter
if (ch>64 && ch<91)
{
    ch=ch+32;
}
//logics for capital letter to small letter
else if (ch>96 && ch<123)
{
    ch=ch-32;
}
//if integer value is not in range of alphabets according to ASCII
else
{
    printf("Invalid input\n");
}
//for printing final result
printf("The output is %c",ch);
return 0;
}


