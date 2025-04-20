#include <stdio.h>
#include <stdlib.h>

struct student
{ char name[30];
  char dob[11]; 
  char rollno[30];
  char branch[30];
  char contactnumber[20];
  char address[50];
 char percentage[50] ;
  struct stdudent *NEXT;
};

struct student *head = NULL;
struct student *tail = NULL;

void addStudent()
{
	getchar();
	struct student *temp = malloc(sizeof(struct student));
	printf("\nEnter name of the student : ");
	scanf("%s", temp->name);
	getchar();

	printf("\nEnter DOB (MM/DD/YYYY) : ");
	scanf("%s", temp->dob);
	getchar();
	printf("\nEnter ROLL NO : ");
	scanf("%s", temp->rollno);
	getchar();
    printf("\nEnter BRANCH : ");
	scanf("%s", temp->branch);
	getchar();
	printf("\nEnter contact no : ");
	scanf("%s", temp->contactnumber);
	getchar();
	printf("\nEnter address : ");
	scanf("%s", temp->address);
	getchar();
	printf("\nEnter per : ");
	scanf("%s", temp->percentage);
	getchar();
	temp->NEXT = NULL;

	if(head == NULL)  /* it means linked list is empty: no record */
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->NEXT = temp;
		tail = temp;
		getchar();
	}
	
}

void displayAllStudents()
{
struct student *temp = head;

if(head == NULL)
	printf("\nNo record: Linked list empty!!");
else
{
	while(temp!=NULL)
	{
		printf("\nName : %s", temp->name);
		printf("\nDOB : %s", temp->dob);
		printf("\nROLL NO : %s", temp->rollno);
		printf("\nBRANCH : %s", temp->branch);
		printf("\nContact no : %s", temp->contactnumber);
		printf("\nAddress : %s", temp->address);
		printf("\npercentage : %s", temp->percentage);
		temp = temp->NEXT;
                if(temp!=NULL){
			printf("\n-----------------------------------------");
			printf("\nPress enter key for the next record..");
			getchar();
		}
	}
}
}
void deleteAllStudent()
{
if(head == NULL)
	printf("\nLinked list empty..");
else
{
	unsigned long int count = 0;
	struct student *temp = head;
	while(temp != NULL)
	{
		struct stduent * var = temp->NEXT;
		free(temp);
		temp = var;
		count++;
	}
	printf("\n*STUDENT INFORMATION DELETED : %ld*\n", count);
}
}

int main()
{
int choice = 1;

while(choice !=0 ){
	printf("\n** Main Menu **");
	printf("\n\tPress 1 to add stdudent");
	printf("\n\tPress 2 to display add stduents");
	printf("\n\tPress 3 to delete");
	printf("\nEnter you choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: addStudent(); break;
		case 2: displayAllStudents(); break;
		case 3: deleteAllStudent(); break;
		default : printf("\nInvalid choice..Please input a valid no");
			  getchar();

	}
}

return 0;
}