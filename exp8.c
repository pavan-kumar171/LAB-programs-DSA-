#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char ssn[15],name[20],dept[5],des[10];
int salary;
long int ph;
struct node *prev,*next;
}*first=NULL;
struct node *last,*temp1,*temp2;
void create(char ssn[15],char name[20],char dept[5],char des[10],int salary,long int ph)
{
temp1=(struct node*)malloc(1*sizeof(struct node));
strcpy(temp1->ssn,ssn);
strcpy(temp1->name,name);
strcpy(temp1->dept,dept);
strcpy(temp1->des,des);
temp1->salary=salary;
temp1->ph=ph;
temp1->prev=NULL;
temp1->next=NULL;

if(first==NULL)
{
 first=last=temp1;
}
else
{
 last->next=temp1;
 temp1->next=NULL;
 temp1->prev=last;
 last=temp1;
 }
}

void display()
{
int count=0;
temp1=first;
if(first==NULL)
{
printf("empty list\n");
return;
}
printf("Employee Details...\n");
while(temp1!=NULL)
{
printf("SSN:%s\nNAME:%s\nDEPT:%s\nDESIGNATION:%s\nSALARY:%d\nPH:%ld\n",temp1->ssn,temp1->name,temp1->dept,temp1->des,temp1->salary,temp1->ph);
temp1=temp1->next;
count++;
}
printf("Number of Nodes=%d\n",count);
}

void inbeg(char ssn[15],char name[20],char dept[5],char des[10],int salary,long int ph)
{
temp1=(struct node*)malloc(1*sizeof(struct node));
strcpy(temp1->ssn,ssn);
strcpy(temp1->name,name);
strcpy(temp1->dept,dept);
strcpy(temp1->des,des);
temp1->salary=salary;
temp1->ph=ph;
temp1->next=first;
first->prev=temp1;
first=temp1;
temp1->prev=NULL;
}
 
 void inend(char ssn[15],char name[20],char dept[5],char des[10],int salary,long int ph)
{
temp1=(struct node*)malloc(1*sizeof(struct node));
strcpy(temp1->ssn,ssn);
strcpy(temp1->name,name);
strcpy(temp1->dept,dept);
strcpy(temp1->des,des);
temp1->salary=salary;
temp1->ph=ph;
last->next=temp1;
temp1->prev=last;
temp1->next=NULL;
last=temp1;
}
 void delbeg()
 {
 if(first==NULL)
 {
 printf("List is empty\n");
 }
 else
 {
 temp1=first->next;
 if(temp1!=NULL)
 {
 temp1->prev=NULL;
 printf("Deleted node is :\n");
 printf("SSN:%s\nNAME:%s\nDEPT:%s\nDESIGNATION:%s\nSALARY:%d\nPH:%ld\n",first->ssn,first->name,first->dept,first->des,first->salary,first->ph);
 free(first);
 first=temp1;
 }
 else
 {
 printf("Deleted node is :\n");
 printf("SSN:%s\nNAME:%s\nDEPT:%s\nDESIGNATION:%s\nSALARY:%d\nPH:%ld\n",first->ssn,first->name,first->dept,first->des,first->salary,first->ph);
 free(first);
 first=NULL;
 }
 }
 }
 
 void delend()
 {
 if(first==NULL)
 {
 printf("empty lis\n");
 }
 else
 {
 temp1=last;
 if(first==last)
 {
 printf("deleted node is :\n");
 printf("SSN:%s\nNAME:%s\nDEPT:%s\nDESIGNATION:%s\nSALARY:%d\nPH:%ld\n",last->ssn,last->name,last->dept,last->des,last->salary,last->ph);
 first=last=NULL;
 free(temp1);
 }
 else
 {
 printf("deleted node is :\n");
 printf("SSN:%s\nNAME:%s\nDEPT:%s\nDESIGNATION:%s\nSALARY:%d\nPH:%ld\n",last->ssn,last->name,last->dept,last->des,last->salary,last->ph);
 last=temp1->prev;
 last->next=NULL;
 free(temp1);
 }
 }
 }
 
 void main()
 {
 int choice;
 char ssn[15], name[20], dept[5],des[10];
 int salary;
 long int ph;
 printf("1.Create\n2.Display\n3.Insert at beginning\n4.Insert at End\n5.Delete at beginning\n6.Delete at end\n7.Exit\n");
 while(1)
 {
 printf("\nEnter your choice\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("Enter Emp SSN,Name,Department,Designation,Salary,Phone\n");
        scanf("%s%s%s%s%d%ld",ssn,name,dept,des,&salary,&ph);
        create(ssn,name,dept,des,salary,ph);
        break;
 case 2:display();
        break;
 case 3:printf("Enter Emp SSN,Name,Department,Designation,Salary,Phone\n");
        scanf("%s%s%s%s%d%ld",ssn,name,dept,des,&salary,&ph);
        inbeg(ssn,name,dept,des,salary,ph);
        break;
 case 4:printf("Enter Emp SSN,Name,Department,Designation,Salary,Phone\n");
        scanf("%s%s%s%s%d%ld",ssn,name,dept,des,&salary,&ph);
        inend(ssn,name,dept,des,salary,ph);
        break;
 case 5:delbeg();
        break;
 case 6:delend();
        break;
 case 7:exit(0);
 }
 }
 }
 
