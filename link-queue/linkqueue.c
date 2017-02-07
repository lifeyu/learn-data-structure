#include "linkqueue.h"

void InitQueue(LinkQueue *queue)
{
	QueueNode *temp = (QueueNode *) malloc (sizeof (QueueNode));
	assert(temp != NULL);

	queue -> front = queue -> tail = temp;
	queue -> tail -> next = NULL;
}

void DestroyQueue(LinkQueue *queue)
{
	ClearQueue(queue);
	free(queue -> front);
	queue -> front = queue -> tail = NULL;
}

void ClearQueue(LinkQueue *queue)
{
	if (QueueEmpty(queue)) return;

	QueueNode *temp = queue -> front -> next;
	while (temp != NULL)
	{
		queue -> front -> next = temp -> next;
		free(temp);
		temp = queue -> front -> next;	
	}
	queue -> tail = queue -> front;
}

boolean QueueEmpty(LinkQueue *queue)
{
	return queue -> front == queue -> tail;
}

int QueueLength(LinkQueue *queue)
{
	int len = 0;

	QueueNode *temp = queue -> front -> next;
	while (temp != NULL)
	{
		len++;
		temp = temp -> next;	
	}

	return len;
}

boolean GetHead(LinkQueue *queue, ElemType *elem)
{
	if (queue -> front == queue -> tail) return false;

	QueueNode *temp = queue -> front -> next;
	*elem = temp -> data;	

	return true;
}

void EnQueue(LinkQueue *queue, ElemType elem)
{
	QueueNode *temp = (QueueNode *) malloc (sizeof (QueueNode));
	assert(temp != NULL);
	temp -> data = elem;
	temp -> next = NULL;

	queue -> tail -> next = temp;
	queue -> tail = temp;
}

boolean DeQueue(LinkQueue *queue, ElemType *elem)
{
	if (queue -> front == queue -> tail) return false;		// 队列为空

	QueueNode *temp = queue -> front -> next;
	*elem = temp -> data;
	queue -> front -> next = temp -> next;
	free(temp);

	if (temp == queue -> tail) queue -> tail = queue -> front;	// 删除头元素后队列为空的情况

	return true;
}

void show(LinkQueue *queue)
{
	QueueNode *temp = queue -> front -> next;
	printf("Front:> ");
	while (temp != NULL)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;	
	}
	printf("< :Tail.\n");
}
