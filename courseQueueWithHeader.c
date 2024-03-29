
#include <stdio.h>
#include <stdlib.h>
#include "structqueue.h"

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

	//deleting all
	while(!isempty(q))
	{ 
		dequeue(q);
	}

	printf("\n");

	//adding fourth data
	temp.courseId = 10082;
	strcpy(temp.courseTitle, "Objected Oriented Programming1- JAVA");
	temp.students = 30;
	temp.year = 201809;
	enqueue(q, temp);

	print(q);

	printf("\n");

    return 0;
}
