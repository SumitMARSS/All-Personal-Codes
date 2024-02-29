#include <stdio.h>
#include <string.h>
struct student//defining structure
{
    char name[300];//string  use for name
    int roll;//roll for students
    float marks;//marks for students
};
int main()
{
    FILE *fp, *ft ;//creating two file
    int option;//taking integer for giving option
    char ch;//defining character
    struct student s1;//defining student structure
    //char newname[300];
    fp=fopen("student.txt","r+");//file open for reading and writing
    fp=fopen("student.txt","w+");
    if (fp==NULL)//if file not created
    {
        printf("File doesn't exist");//show if file not created
        void exit(int status);//taking exit
    }
    else
    {
        printf("File is created");
    }
    while (1)
    {
        printf("\n Enter 1 if you want to open file record");
        printf("\n Enter 2 if you want to opening of existing file");
        printf("\n Enter 3 if you want to continue from file");//moving to a specific location
        printf("\n Enter 4 if you want to just go back and then continue in file");//moving to a specific location
        printf("\n Enter 5 if you want to copy a file record in another file");
        printf("\n Enter 6 if you want to count tab, space, characters in file");
        printf("\n Enter 7 if you want to exit");
        printf("\nThe number is ....\n");
        scanf("%d",&option);//taking input for choice
    switch (option)//using switch function for combining problems
    {
        case 1:
            do
            {
                printf("Enter the name,roll,marks of student\n");
                scanf("%s\n%d\n%f",&s1.name,&s1.roll,&s1.marks);//taking input for structure defined
                fwrite(&s1,sizeof(s1),1,fp);//writing in file
                printf("Do you want to continue if yes give input as 'y'\n");//option for continue
                //scanf("%c",&ch);
                fflush(stdin);
                ch=getche();//getting input for character
                //ch=getchar();
            } while (ch=='y');//condition for continue loop
            break;
        case 2:
            rewind(fp);//taking rewind
            printf("Your records are:\n");
            //priniting all records we taken in structure by using always true condition
            while (fread(&s1,sizeof(s1),1,fp)==1)
            {
                printf("%s\t%d\t%f\n",s1.name,s1.roll,s1.marks);
            }
            break;
        case 3:
            fseek(fp,0,SEEK_END);//continue from where we left the records
            do
            {
                printf("Enter the name,roll,marks of student\n");
                scanf("%s\n%d\n%f",&s1.name,&s1.roll,&s1.marks);//taking input for structure defined
                fwrite(&s1,sizeof(s1),1,fp);//writing in file
                printf("Do you want to continue if yes give input as 'y'\n");//option for continue
                //scanf("%c",&ch);
                fflush(stdin);
                ch=getche();//getting input for character
                //ch=getchar();
            } while (ch=='y');//condition for continue loop
            break;
        case 4:
            fseek(fp,-sizeof(s1),SEEK_CUR);//continue from where we left the records just one back
            do
            {
                printf("Enter the name,roll,marks of student\n");
                scanf("%s\n%d\n%f",&s1.name,&s1.roll,&s1.marks);//taking input for structure defined
                fwrite(&s1,sizeof(s1),1,fp);//writing in file
                printf("Do you want to continue if yes give input as 'y'\n");//option for continue
                //scanf("%c",&ch);
                fflush(stdin);
                ch=getche();//getting input for character
                //ch=getchar();
            } while (ch=='y');//condition for continue loop
            break;
        case 5:
            ft=fopen("teacher.txt","r+");//opening a new file
            ft=fopen("teacher.txt","w+");//opening a new file
            rewind(fp);//taking rewind of old file
            while (fread(&s1,sizeof(s1),1,fp)==1)//copying all records in new file using always true condition
            {
                fwrite(&s1,sizeof(s1),1,ft);//without condition
            }
            rewind(ft);//taking rewind
            printf("Your records in copy file are:\n");
            while (fread(&s1,sizeof(s1),1,ft)==1)//priniting all records we taken in structure in new file by using always true condition
            {
                printf("%s\t%d\t%f\n",s1.name,s1.roll,s1.marks);//priniting all record by new function
            }
            break;
        case 6:
            fp=fopen("student.txt","r+");//file open for reading and writing
            fp=fopen("student.txt","w+");
            rewind(fp);//taking fp file rewind
            int a=0,b=0,c=0;//declaring integer
            char ch1;//defining character
            /*while (fread(&s1,sizeof(s1),1,fp)==1)//always true
            {
                ch1=fgetc(fp);
                if (ch1==EOF)//break condition
                {
                    break;
                }
                else
                {
                    a=a+1;//adding character
                    if (ch1==' ')
                    {
                        b=b+1;//adding space
                    }
                    else
                    {
                        c=c+1;//adding tabs and new lines
                    }  
                } 
            }*/
            ch1=fgetc(fp);
                while (ch1!=EOF)
                {
                    a=a+1;
                }
            printf("Number of charcters in file is %d\n",a);//printing total character
            //printf("Number of spaces in file is %d\n",b);//printing total spaces
            //printf("Number of tabs in file is %d\n",c);//printing total tabs
            fclose(fp);//closing file
            break;  
            
        case 7:
            printf("WRONG CHOICE");
            fclose(fp);//just closing file
            return 0;
            break;   
    }
    }
}
