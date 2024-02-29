#include <stdio.h>
int main()
{
    int a,n,rem,base=1,sum=0;//defining value
    printf("Enter 1 for binary to decimal and 2 for decimal to binary in integer\n");
    scanf("%d",&a);//taking input for performing activities
    switch (a)//using switch case
    {
        case 1:
            printf("Enter the number of binary\n");
            scanf("%d",&n);//taking input binary number
            while (n>0)//until loop continue
            {
                rem=n%10;//finding remainder
                sum=sum+rem*base;//finding the decimal number by multiplying rem multiple of 2 and adding them
                n=n/10;//new number for continue
                base=base*2;//base is multiple of 2
            }
            printf("The decimal number is :%d",sum);//output for decimal number
            break;//for coming out after performing activity
        case 2:
            printf("Enter the number of decimal\n");
            scanf("%d",&n);//taking input decimal number
            while (n>0)//until loop continue
            {
                rem=n%2;//finding remainder
                sum=sum+rem*base;//finding the binary number by multiplying rem multiple of 10 and adding them
                n=n/2;//continue num
                ber for finding binary
                base=base*10;//base is multiple of 10
            }
            printf("The binary number is :%d",sum);//output for binary number
            break;//for coming out after performing activity
        default:
            printf("INVALID INPUT");//if input is not in 1,2
            break;//for coming out after performing activity
    }
}