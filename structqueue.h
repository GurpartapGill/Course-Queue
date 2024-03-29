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

