#include <stdio.h>
#include <stdlib.h>

struct node
{
    int element;//queue element
    struct node *link;//a pointer pointing the node of its own type
};

    struct node *front=NULL;
    struct node *rear=NULL;

void cirqins() //Insert elements in Queue
{
    int n,data,i=1;
    printf("Enter the number of node you want to made:\n");
    scanf("%d",&n);
    while (i<=n)
    {
        struct node* ptr;
        printf("Enter the data of element %d :\n",i);
        scanf("%d",&data);
        i++;
	    ptr = (struct node*)malloc(sizeof(struct node));
	    ptr->element = data;
	    ptr->link = NULL;
	    if((rear==NULL)&&(front==NULL))
	    {
		    front = rear = ptr;
		    rear->link = front;
	    }
	    else
	    {
            rear->link=ptr;
            rear=ptr;
            ptr->link=front;
	    }
    }
}
int cirqdel() // Delete an element from Queue
{
    int x;
	struct node* ptr;
	ptr = front;
	if((front==NULL)&&(rear==NULL))
        {
            x==-1;
            printf("Queue is Empty\n");
            return x;
        }	
	else if(front== rear)
        {
            x=front->element;
		    front = rear = NULL;
		    free(ptr);
            return x;
	    }
	else
        {
            x=front->element;
		    front = front->link;
		    rear->link = front;
		    free(ptr);
            return x;
	    }
}
void cirqdisplay()// Print the elements of Queue
{ 
    int i=1;
	struct node* ptr;
	ptr = front;
	if((front==NULL)&&(rear==NULL))
		printf("Queue is Empty\n");
	else{
		do{
			printf("Element %d is %d\n",i,ptr->element);
			ptr=ptr->link;
            i++;
		}while(ptr != front);
	}
} 
int main()
{
	int choice,item;
	do{
		printf("\n1. to insert the Data in Queue\n");
        printf("2. to delete an element\n");
        printf("3. to display the queue\n");
        printf("4. to exit from program \n");
        printf("You can also enter any other number just to END the PROGRAM\n");
        printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
                cirqins();
				break;
			case 2:
				item=cirqdel();
                if (item!=-1)
                {
                    printf("The element %d is deleted from the queue.\n",item);
                }
				break;
            case 3:
                cirqdisplay();
                break;
			
			default:
				printf("Wrong Choice\nINVALID INPUT\n");
                printf("Your program is TERMINATED......\n");
                exit(1);
			
		}
	}while(choice<=3);
return 0;
}