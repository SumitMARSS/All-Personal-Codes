#include <stdio.h>
int main()
{
    int num;//defining integer
    while (1)
    {
        printf("Enter your choice");//giving choice
        printf("\n Enter 1 if you want to read from a file");
        printf("\n Enter 2 if you want to write to a file");
        printf("\nThe number is ....\n");
        scanf("%d",&num);//taking input the choice
        char name[300];//string(character array)
        FILE *fp;//file assigning
        switch(num)//using switch case
        {
            case 1:
                fp=fopen("start.txt","r+");//opening file in read mode
                fscanf(fp,"%s",name);//reading from file
                printf("The content in file is %s\n",name);//displaying from file
                fclose(fp);//closing file
                break;
            case 2:
                char name[300]="I am a student in IIIT KALYANI";//for writing in file
                fp=fopen("start.txt","a");//using amber just to write after what is written in file
                fprintf(fp,"%s",name);//writing in file
                fclose(fp);//closing file
                break;
        }
    }   //(c),(d) reading and writing from file
}