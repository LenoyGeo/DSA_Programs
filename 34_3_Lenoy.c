//Ascending Order of Roll Numbers of Students
#include<stdio.h>
#include<string.h>
struct student
{
	char name[100];
	int rollno;
	float perc;
}s[5],temp[5];
int main()
{
	int i,j;
	for(i=0;i<5;i++)
	{
	printf("Enter Name:");
	scanf("%s",s[i].name);
	printf("Enter Roll Number:");
	scanf("%d",&s[i].rollno);
	printf("Enter Percentage:");
	scanf("%f",&s[i].perc);	
	}
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(s[i].rollno>s[j].rollno)
			{
				temp[i]=s[i];
				s[i]=s[j];
				s[j]=temp[i];
			}
		}
	}
	printf("\nBooks in Ascending Order of Roll Numbers:");
	for(i=0;i<5;i++)
    {
    printf("\nName: %s",s[i].name);
	printf("\nRoll No.: %d",s[i].rollno);
	printf("\nPercentage: %.2f",s[i].perc);	
	}	
    return 0;
}