/*
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int courseId;
	char courseTitle[50];
	int students;
	int year;
}course;

typedef struct node
{
    course data;
    struct node *next;
}
node, *nodeptr;

typedef struct queue
{
    nodeptr head;
    nodeptr tail;
}
*queue;


queue initialize(void);
int isempty(queue q);
void enqueue(queue q, course c);
void dequeue(queue q);
void print(queue q);


int main()
{
	//int n;
	course temp, output;
	queue q = initialize();
	
	//first data
	temp.courseId = 20799;
	strcpy(temp.courseTitle, "Data Structures And Algorithm Development");
	temp.students = 12;
	temp.year = 202001;
	enqueue(q, temp);

	//second data
	temp.courseId = 37221;
	strcpy(temp.courseTitle, "Web Services Using C# and .NET Programming");
	temp.students = 36;
	temp.year = 202001;
	enqueue(q, temp);

	//third data
	temp.courseId = 32758;
	strcpy(temp.courseTitle, "Enterprise Java Development");
	temp.students = 25;
	temp.year = 201909;
	enqueue(q, temp);

	print(q);

	printf("\n");

	while(!isempty(q))
	{ 
		dequeue(q);
	}

	printf("\n");

	//fourth data
	temp.courseId = 10082;
	strcpy(temp.courseTitle, "Objected Oriented Programming1- JAVA");
	temp.students = 30;
	temp.year = 201809;
	enqueue(q, temp);

	print(q);

	printf("\n");

    return 0;
}

queue initialize()
{
	queue q=(queue)malloc(sizeof(course));
    q->head = NULL;
    q->tail = NULL;
	return q;
}

int isempty(queue q)
{
    return (q->head == NULL);
}

void enqueue(queue q, course c)
{

	nodeptr np = (nodeptr)malloc(sizeof(node));
	np->data = c;
	np->next = NULL;

	if(isempty(q))
	{
		q->head = np;
		q->tail = np;
	}
	else
	{
		q->tail->next = np;
		q->tail = np;
	}
}

void dequeue(queue q)
{
	struct node *ptr;  

	if(isempty(q))
	{
		printf("Attempt to remove from empty list \n");
		exit(1);
	}

    else   
    {  
        ptr = q->head;  
        q->head = q->head -> next;  
        free(ptr);  
    }  
}

void print(queue q)  
{  
    struct node *ptr;  
    ptr = q->head;      
    if(q->head == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nCOURSES .....\n");  
        while(ptr != NULL)   
        {  
 			printf("\n%d", ptr -> data.courseId);
			printf("\n%s", ptr -> data.courseTitle);
			printf("\n%d", ptr -> data.students);
			printf("\n%d\n", ptr -> data.year);
            ptr = ptr -> next;  
        }  
    }  
}  

