#include "cyclequeue.h"

void InitQueue(CycleQueue *queue)
{
	queue -> base = (ElemType *) malloc (sizeof (ElemType) * MAXSIZE);
	assert(queue -> base != NULL);

	queue -> front = queue -> rear = 0;
}

void DestroyQueue(CycleQueue *queue)
{
	free(queue -> base);
	queue -> base = NULL;
}

void ClearQueue(CycleQueue *queue)
{
	queue -> front = queue -> rear = 0;
}

boolean QueueEmpty(CycleQueue *queue)
{
	return queue -> front == queue -> rear;
}

int QueueLength(CycleQueue *queue)
{
	if (queue -> rear >= queue -> front)
	{
		return queue -> rear - queue -> front;
	}
	else
	{
		return MAXSIZE - queue -> front + queue -> rear;	
	}
}

boolean GetHead(CycleQueue *queue, ElemType *elem)
{
	if (QueueEmpty(queue)) return false;	

	*elem = queue -> base[queue -> front];
}

void EnQueue(CycleQueue *queue, ElemType elem)
{
	if (((queue -> rear + 1) % MAXSIZE) == queue -> front)
	{
		printf("队列已满,不能入队!\n");	
		return;
	}	

	queue -> base[queue -> rear] = elem;
	queue -> rear = (queue -> rear + 1) % MAXSIZE;
}

boolean DeQueue(CycleQueue *queue, ElemType *elem)
{
	if (QueueEmpty(queue)) return false;	

	*elem = queue -> base[queue -> front];
	queue -> front = (queue -> front + 1) % MAXSIZE;

	return true;
}

void show(CycleQueue *queue)
{
	for (int i = queue -> front; i != queue -> rear;)
	{
		printf("%d ", queue -> base[i]);	
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}
