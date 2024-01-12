#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int sem;
    char usn[11],name[20],branch[20],phone[11];
    struct SLL*next;
}
typedef struct SLL node;
node *start=NULL;
node *getnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the student details : usn name branch sem phone number \n");
    scanf("%s",newnode->usn);
    scanf("%s",newnode->name);
    scanf("%s",newnode->branch);
    fflush(stdin);
    scanf("%d",&newnode->sem);
    scanf("%d",&newnode->phone);
    newnode->next=NULL;
    return newnode;
}
void insertBegin()
{
    node *newnode;
    newnode=getnode();
    if(start==NULL)
        start=newnode;
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
void insertEnd()
{
    node *newnode,*temp;
    newnode=getnode();
    if(start==NULL)
        start=newnode;
    temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}
void deleteBegin()
{
    node *temp=start;
    if(start=NULL)
        printf("Linked list is empty");
    printf("Deleted node is %s ",temp->usn);
    start=temp->next;
    free(temp);
}
void display()
{
    int count=0;
    node *temp=start;
    
}