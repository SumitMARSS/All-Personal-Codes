#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,k;//defining integer value
    char a[30],b[30];//string  use for a,b
    puts("Enter your name : \n");
    gets(a);//taking input string a
    printf("your name in short is :\n%c",a[0]);
    for(i=0;a[i]!='\0';i++)//condition when we get end array
    {
        if(a[i]==' ')//if we get black
        {
            printf(".%c",a[i+1]);//printing the alphabate
        }
    }
    for(i=0;a[i]!='\0';i++)//in our array when we get end array
    {
        if(a[i]==' ')//if we get black
        {
            for(j=i,k=0;a[j]!='\0';j++,k++)
            {
                b[k]=a[j];//copying the second word in another array
            }
        } 
    }
    b[k]='\0';//end conditions
    for(i=2;b[i]!='\0';i++)//conditon for last word
    {
        printf("%c",b[i]);//printing the last word
    }
}