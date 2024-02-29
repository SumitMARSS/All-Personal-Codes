#include <stdio.h>

char main()
//defining inputs
{char ch;
//getting input
printf("Enter the character you want to check\n");
scanf("%c",&ch);
//logics if integer value is not in range of alphabets according to ASCII
if (ch>=65 && ch<=90 || ch>=97 && ch<=122)
{   
    //logics if given alphabet is vowel or consonent
    if (ch =='A'||'E'||'I'||'0'||'U'||'a'||'e'||'i'||'o'||'u')
        {
            printf("%c is vowel",ch);//for printing the result
        }
    else
        {
            printf("%c is consonent",ch);//for printing the result
        }
}
//if you don't enter the alphabet or something other than given range
else
{
    printf("Invalid input");
}
return 0;
}