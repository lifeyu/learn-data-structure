#include "seqqueue.h"

void InitQueue(SeqQueue *queue)
{
	queue -> base = (ElemType *) malloc (sizeof (ElemType) * MAXSIZE);
	assert(queue -> base != NULL);

	queue -> front = queue -> rear = 0;
}

void DestroyQueue(SeqQueue *queue)
{
	free(queue -> base);
	queue -> base = NULL;
}

void ClearQueue(SeqQueue *queue)
{
	queue -> front = queue -> rear = 0;
}

boolean QueueEmpty(SeqQueue *queue)
{
	return queue -> front == queue -> rear;
}

int QueueLength(SeqQueue *queue)
{
	return queue -> rear - queue -> front;
}

boolean GetHead(SeqQueue *queue, ElemType *elem)
{
	if (QueueEmpty(queue)) return false;	

	*elem = queue -> base[queue -> front];
}

void EnQueue(SeqQueue *queue, ElemType elem)
{
	if (queue -> rear >= MAXSIZE)
	{
		printf("队列已满,不能入队!\n");	
		return;
	}	

	queue -> base[queue -> rear++] = elem;
}

boolean DeQueue(SeqQueue *queue, ElemType *elem)
{
	if (QueueEmpty(queue)) return false;	

	*elem = queue -> base[queue -> front++];

	return true;
}

void show(SeqQueue *queue)
{
	for (int i = queue -> front; i < queue -> rear; i++)
	{
		printf("%d ", queue -> base[i]);	
	}
	printf("\n");
}
