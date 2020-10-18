#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node2{
char money[100];
struct node2 *next2;
}node2;

typedef struct node1{
char q[100];
struct node1 *next;
}node1;

typedef struct moneylist{
node2 *head2;
}moneylist;

typedef struct list{
node1 *head;
}list;

typedef struct node
{
    char data[50];
    struct node *link;
}node;

typedef struct queue
{
    node *head;
    node *tail;
}queue;


void create1(queue *);
void insert(FILE *,queue *,queue *,queue *,queue *);
void display(list *,moneylist *,queue *,queue *,queue *,queue *);

void create2(moneylist *);
void create(list *);
void assign(FILE *, list *);
void assign2(FILE *, moneylist *);
void init(list *li)
{
li->head=NULL;
}

void init2(moneylist *li2)
{
li2->head2=NULL;
}

int main()
{
list *li;
moneylist *li2;
li=(list *)malloc(sizeof(list));
init(li);
li2=(moneylist *)malloc(sizeof(moneylist));
init2(li2);
int i=15;
int j=16;
while(i>0){
create(li);
i--;
}
while(j>0){
create2(li2);
j--;
}
printf("\n  \t\t Welcome TO KBC \n   RULES:You have 15 Q...each Q has 4 options...\n   You have 2 lifelines namely 50:50 and Audience poll\n     \t\t Good Luck\n \n \t\t   MONEY TREE\n");
FILE *fp;
FILE *fp1;
FILE *fp2;
char buff[100];
fp=fopen("Questions1.txt","r");
fp1=fopen("money.txt","r");
fp2=fopen("money_list.txt","r");

while(fgets(buff,100,fp1)!=NULL)
{
    printf("\t   %s",buff);
}
assign(fp,li);
assign2(fp2,li2);
    queue *q1;
	queue *q2;
	queue *q3;
	queue *q4;
	q1=(queue *)malloc(sizeof(queue));
	q2=(queue *)malloc(sizeof(queue));
	q3=(queue *)malloc(sizeof(queue));
	q4=(queue *)malloc(sizeof(queue));
	q1->head=q1->tail=NULL;
	q2->head=q2->tail=NULL;
	q3->head=q3->tail=NULL;
	q4->head=q4->tail=NULL;
	

	
	for(int i=0;i<60;i++)
	{
	create1(q1);
	}
	for(int i=0;i<15;i++)
	{
	create1(q2);
	}
	for(int i=0;i<30;i++)
	{
	create1(q3);
	}
	for(int i=0;i<15;i++)
	{
	create1(q4);
	}
	
	insert(fp1,q1,q2,q3,q4);
	display(li,li2,q1,q2,q3,q4);


fclose(fp);
fclose(fp1);
fclose(fp2);

return 0;
}
void assign(FILE *fp,list *li)
{
char buf[5000];
node1 *w = li->head;
for(int j=15;j>0;j--)
{
fgets(buf,5000,fp);
strcpy(w->q,buf);
w=w->next;
}
}

void assign2(FILE *fp2,moneylist *li2)
{
char buf[5000];
node2 *w = li2->head2;
for(int j=16;j>0;j--)
{
fgets(buf,5000,fp2);
strcpy(w->money,buf);
w=w->next2;
}
}






void create(list *li)
{
node1 *temp=(node1 *)malloc(sizeof(node1));
temp->next=NULL;
strcpy(temp->q,"hello how are you");
if(li->head==NULL)
{
li->head=temp;
}
else
{
node1 *p=li->head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
}
}


void create2(moneylist *li2)
{
node2 *m=(node2 *)malloc(sizeof(node2));
m->next2=NULL;
strcpy(m->money,"hello how are you");
if(li2->head2==NULL)
{
li2->head2=m;
}
else
{
node2 *p2=li2->head2;
while(p2->next2!=NULL)
{
p2=p2->next2;
}
p2->next2=m;
}
}


void create1(queue *qi)
{
node *temp=(node *)malloc(sizeof(node));
strcpy(temp->data,"hello");
temp->link=NULL;
if(qi->head==NULL)
{
qi->head=qi->tail=temp;
}
else
{
qi->tail->link=temp;
qi->tail=temp;
}
}


void insert(FILE *fp1, queue *q1, queue *q2,queue *q3,queue *q4)
{
fp1=fopen("options1.csv","r");
char s[5000];
char *p;
node *temp=q1->head;
node *temp1=q2->head;
node *temp2=q3->head;
node *temp3=q4->head;
while(fgets(s,5000,fp1)!=NULL)
{
    p=strtok(s,",");
    strcpy(temp->data,p);
    temp=temp->link;
    for(int i=0;i<3;i++)
    {
    p=strtok(NULL,",");
    strcpy(temp->data,p);
    temp=temp->link;
    }

    p=strtok(NULL,",");
    strcpy(temp1->data,p);
    temp1=temp1->link;

    p=strtok(NULL,",");
    strcpy(temp2->data,p);
    temp2=temp2->link;

    p=strtok(NULL,",");
    strcpy(temp2->data,p);
    temp2=temp2->link;

    p=strtok(NULL,",");
    strcpy(temp3->data,p);
    temp3=temp3->link;
}
fclose(fp1);
}

void display(list *li,moneylist *li2,queue *q1,queue *q2,queue *q3,queue *q4)
{
int o1=1;
int o=0;
int i1=0;
int i2=0;
node1 *p=li->head;
node2 *m=li2->head2;
node2 *m2=li2->head2;
node2 *m3=li2->head2;
node *temp=q1->head;
node *temp1=q2->head;
node *temp2=q3->head;
node *temp3=q4->head;
char s[20];
int n;
for(int i=0;i<15;i++)
{
m2=m2->next2;
printf("\n------------------------------------------------\n");
printf("\nHere is your Question No: %d for Rs.%s ",o1,m2->money);
printf("\n %d .%s \n",o1,p->q);

o1++;
p=p->next;
for(int j=0;j<4;j++)
{
printf("%s \t",temp->data);
temp=temp->link;
}


rec:

if(i1==0 && i2==0)
{
printf("\npress --> 1: 50:50   2: audience poll  3:QUIT  0:To answer   ---> ");
scanf("%d",&n);
}
else if(i1==0)
{
printf("\npress -->  1: 50:50  3:QUIT   0:To answer  ---> ");
scanf("%d",&n);
}
else
{
printf("\npress -->  2: audience poll  3:QUIT  0:To answer  ---> ");
scanf("%d",&n);
}
if(n==1)
{
 for(int k=0;k<2;k++)
    {
        printf("%s \t",temp2->data);
        temp2=temp2->link;
    }
    printf("\n");
    i1=1;
}
else if(n==2)
{
    printf("%s \n",temp3->data);
    temp3=temp3->link;
    i2=1;
}
else if(n==3)
{
    printf("You quit the game by winning Rs.%s",m3->money);
    break;
}
else if(n==0)
{
temp2=temp2->link->link;
temp3=temp3->link;
}
else
{
printf("\nplease enter the correct choice");
goto rec;
}
printf("enter your answer  ");
scanf("%s",s);


    if(!(strcmp(s,temp1->data)))
    {
    printf("\n.....correct answer......\n");
    m=m->next2;
    m3=m3->next2;
    
    printf("\nYou have won : Rs. %s\n",m->money);
    o++;
    }
    else
    {
    printf("\n.....Sorry wrong answer......\n");
    printf("The correct answer is  %s \n",temp1->data); 
    printf("......Sorry!!! You Lost.........\n");
    printf("You won only : Rs. %s\n",m->money);
    break;
    }
   
 
temp1=temp1->link;
}
if(o==15)
    printf("\n.....Congratulations!!!! You Won 1 Crore.....\n");
}
