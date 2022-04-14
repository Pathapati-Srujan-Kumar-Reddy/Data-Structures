#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

struct queue {
    int items[QUEUE_SIZE];
    int f;
    int r;
    int count;
};
typedef struct queue QUEUE;

int insert_rare(int item,QUEUE *q)
{
    if(q->count == QUEUE_SIZE)
    {
        printf("\nQueue is full");
        return 0;
    }
    q->r = (q->r+1)%QUEUE_SIZE;
    q->items[q->r] = item;
    (q->count)++;
 
}
int delete_front(QUEUE *q)
{
    if(q->count == 0)
    {
        printf("\nQueue is empty");
        return 0;
    }
    printf("\nThe element deleted is %d\n",q->items[q->f]);
    q->f = (q->f+1)%QUEUE_SIZE;
    q->count--;
}

int display(QUEUE *q)
{
    int i,j;
    if(q->count==0)
    {
        printf("\nQueue is empty");
        return 0;
    }
    printf("\nThe Queue contents are:\n");
    i = q->f;
    for(j=1;j<=q->count;j++)
    {
    printf("%d\t",q->items[i]);
    i=(i+1)%QUEUE_SIZE;
    }
}

int main()
{
    QUEUE q;
    q.f = 0;
    q.r = -1;
    q.count = 0;
    int input,item;
    for(;;)
    {
        printf("\n1 to insert rare");
        printf("\n2 to delete front");
        printf("\n3 to display the contents of queue");
        printf("\n4 to exit");
        printf("\nenter the choice: ");
        scanf("%d",&input);
        switch(input)
        {
            case 1: printf("\nEnter the item to be inserted: ");
                    scanf("%d",&item);
                    insert_rare(item,&q);
                    display(&q);
                    break;
            case 2: delete_front(&q);
                    display(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid Choice "); continue;

        }

    }
}