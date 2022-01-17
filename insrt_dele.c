#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{char name[30];
int roll_no;
int prn;
struct node *next;
};
struct node *create()
{
int p,r;
char n[30];
struct node *head;
head=(struct node*)malloc(sizeof(struct node));
printf("\nEnter roll no.:");
scanf("%d",&r);
printf("\nEnter PRN:");
scanf("%d",&p);
printf("\nEnter name:");
scanf("%s",n);
head->prn=p;
head->roll_no=r;
strcpy(head->name,n);
head->next=NULL;
return head;
}
void add(int m,struct node *head)
{
    struct node *temp,*q;
    q=head;
    int p,r;
    char n[20];
    for (int i = 0; i < m; i++)
    {
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter roll no.:");
    scanf("%d",&r);
    printf("\nEnter PRN:");
    scanf("%d",&p);
    printf("\nEnter name of member:");
    scanf("%s",n);
    temp->prn=p;
    temp->roll_no=r;
    strcpy(temp->name,n);
    q->next=temp;
    q=temp;

    }
    
}
void display(struct node *head)
{
    printf("\nPRN\tRoll_No\tName");
while(head!=NULL)
{
    printf("\n%d\t%d\t%s\t",head->prn,head->roll_no,head->name);
    head=head->next;
    printf("\n");
}
}
void secret(struct node *head)
{
    struct node *new;
    char na_me[30];
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data of secretary(prn,roll no.,name)");
    scanf("%d%d",&new->prn,&new->roll_no);
    scanf("%s",na_me);
    strcpy(new->name,na_me);
    new->next=NULL;
    while(head!=NULL && head->next!=NULL)
    {
        head=head->next;
    }
 head->next=new;
}
struct node *deleteP(struct node *head)
{
struct node *p;
p=head->next;
free(head);
return p;
}
struct node *deleteS(struct node *head)
{struct node *prv;
 while(head!=NULL && head->next!=NULL)
 {prv=head;
     head=head->next;

 }
 prv->next=NULL;
 free(head);
 
}
void deleteM(int prn1,struct node *head)
{
struct node *q;
while (head->prn!=prn1)
{
    q=head;
    head=head->next;
}
q->next=head->next;
free(head);


}
int main()
{int choice,m,p;
struct node *head;
char b;
do{
printf("1.Crete");
printf("\n2.Addmember");
printf("\n3.Add s");
printf("\n4.Delete president");
printf("\n5.Delete Secretary");
printf("\n6.Delete member");
printf("\n7.Display");
printf("\nEnter choice:");
scanf("%d",&choice);
switch (choice)
{
case 1:
head=create();
break;
case 2:
printf("Enter no. of members");
scanf("%d",&m);
add(m,head);
break;
case 3:
secret(head);
break;
case 4:
head=deleteP(head);
display(head);
break;
case 5:
deleteS(head);
display(head);
break;
case 6:
printf("Enter PRN number of the member to be deleted: ");
scanf("%d",&p);
deleteM(p,head);
display(head);
break;
case 7:
display(head);
default:
    break;
}
/*printf("\nDo yoy want to go to choices again(Y/N):");
scanf("%s",b);*/
}while(choice!=8);
}
