#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

struct queue {
    int items[QUEUE_SIZE];
    int front;
    int rare;
};
typedef struct queue QUEUE;

int insert_rare(int item,QUEUE *q)
{
    if(q->rare==QUEUE_SIZE-1)
    {
        printf("\nQueue is full, insertion at rare end is not possible");
        return 0;
    }
    (q->rare)++;
    q->items[q->rare] = item;
 
}
int delete_front(QUEUE *q)
{
    if(q->front > q->rare)
    {
        printf("\nQueue is empty, deletion is not possible");
        return 0;
    }
    printf("\nThe element deleted is %d\n",q->items[q->front++]);
    if(q->front > q->rare)
    {
        q->front = 0;
        q->rare = -1;
    }
}

int display(QUEUE *q)
{
    int i;
    if(q->front > q->rare)
    {
        printf("\nQueue is empty, can't display content");
        return 0;
    }
    printf("\nThe Queue contents are:\n");
    for(i=q->front;i<=q->rare;i++)
    printf("%d\t",q->items[i]);

}

int main()
{
    QUEUE q;
    q.front = 0;
    q.rare = -1;
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