//Name: Sumit Kumar   Reg no: 752    Assignment: 2
#include<stdio.h>
#include <stdlib.h>
struct employee//defining structure
{
	int id;
    char name[100];
	char category[100];
};
typedef struct employee em;
em *emp[10];
//user define read function
em *read(em *p)
{
	printf("Enter the name:\n");
	fflush(stdin);//flushing the waste data
	gets(p->name);
	printf("Enter the id:\n");
	scanf("%d",&p->id);
	printf("Enter the category:\n");
	fflush(stdin);//flushing the waste data
	gets(p->category);
}
//user define display function
em *display(em *p)
{
    printf("%d\t%s\t%s\n",p->id,p->name,p->category);
}
//user define modify function
em *modify(em *p, int id1)
{
    if(p -> id == id1)//condition for getting the same id and modifing the id
    {
        printf("Enter the modified name:\n");
	    fflush(stdin);//flushing the waste data
	    gets(p->name);

	    printf("Enter the modified identity:\n");
	    scanf("%d",&p->id);

	    printf("Enter the modified category:\n");
	    fflush(stdin);//flushing the waste data
	    gets(p->category);  
    }
}
//user define search function
em *search(em *p,int id1)
{
	int count=0;
	if(p->id==id1)//condition for getting the same id and displaying the id
	{
		printf("Details are:\n");
		printf("Name: %s\n",p->name);
		printf("Identity: %d\n",p->id);
		printf("Category: %s\n",p->category);
	}
}
int main()
{
	int choice,p,i, id1;
	while(1)
	{
		printf("\nPress 1 to read the information of employees\n");
		printf("Press 2 to display the information of employees\n");
		printf("Press 3 to modify the information of a particular employee\n");
		printf("Press 4 to search a particular employee\n");
		printf("Press 5 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the number of employees\n");
			scanf("%d", &p);//taking input number of employees
			for(i = 0; i < p; i++)
			{
				emp[i]=(em *)malloc(sizeof(em));
				printf("Enter the details of employee %d\n",i+1);
				read(emp[i]);//using user define function for reading 
			}
            break;
            case 2:
            printf("The Details of employee's:\nID\t Name\t Category\n");
            for(i = 0; i < p; i++)//Displaying all the details
			{
				display(emp[i]);
			}
            break;
            case 3:
                printf("Enter the Identity of the employee to modify:  ");
                scanf("%d",&id1);//taking input the identity we want to modify
                for(i = 0; i < p; i++)
                {
                    modify(emp[i], id1);//using user define function for modifing   
                }
            break;
            case 4:
			printf("Enter the identity of the employee you want to search\n");
			scanf("%d",&id1);//taking input the identity we want to search
			for(i=0;i<p;i++)
			{
				search(emp[i],id1);//using user define function for searching
			}
			for(i=0;i<p;i++)
			{
				free(emp[i]);//releasing the space
			}
			break;
            case 5:
                printf("Invalid input");
                return 0;//ending our program
        }
	}
}