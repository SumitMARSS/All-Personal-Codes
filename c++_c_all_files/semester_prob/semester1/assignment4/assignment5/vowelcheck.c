#include <stdio.h>

char main()
//defining inputs
{char ch;
//getting input
printf("Enter the alphabet :\n",ch);
scanf("%c",&ch);
//logics if integer value is not in range of alphabets according to ASCII
if (ch>=65 && ch<=90 || ch>=97 && ch<=122)
{
//logics if given alphabet is vowel or consonent
switch (ch)
{
case 'a':
    printf("%c is a vowel",ch);
    break;
case 'e':
    printf("%c is a vowel",ch);
    break;
case 'i':
    printf("%c is a vowel",ch);
    break;
case 'o':
    printf("%c is a vowel",ch);
    break;
case 'u':
    printf("%c is a vowel",ch);
    break;
case 'A':
    printf("%c is a vowel",ch);
    break;
case 'E':
    printf("%c is a vowel",ch);
    break;
case 'I':
    printf("%c is a vowel",ch);
    break;
case 'O':
    printf("%c is a vowel",ch);
    break;
case 'U':
    printf("%c is a vowel",ch);
    break;
default:
    printf("%c is a consonent",ch);
    break;
}
}
//if you don't enter the alphabet or something other than given range
else
{
    printf("You have entered wrong input");
}
return 0;
}