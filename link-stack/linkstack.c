#include "linkstack.h"

void InitStack(LinkStack *stack)
{
	*stack = NULL;
}

void DestroyStack(LinkStack *stack)
{
	ClearStack(stack);
	free(stack);
}

void ClearStack(LinkStack *stack)
{
	if (*stack == NULL)
	{
		printf("链式栈为空!\n");	
		return;
	}	

	while (!StackEmpty(stack))
	{
		Pop(stack);	
	}
}

boolean StackEmpty(LinkStack *stack)
{
	//PtrToNode temp = *stack;
	return *stack == NULL;
}

int StackLength(LinkStack *stack)
{
	int size = 0;

	if (StackEmpty(stack))
	{
		return size;	
	}
	else
	{
		PtrToNode temp = *stack;
		while (temp != NULL)
		{
			size++;
			temp = temp -> next;
		}	
	}

	return size;
}

boolean GetTop(LinkStack *stack, ElemType *elem)
{
	if (StackEmpty(stack)) 
	{
		printf("栈空间已空，不能取栈顶元素.\n");	
		return false;
	}

	PtrToNode temp = *stack;
	*elem = temp -> data;

	return true;
}

void Push(LinkStack *stack, ElemType elem)
{
	PtrToNode temp = malloc ( sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	if (*stack == NULL)
	{
		*stack = temp;
		temp -> next = NULL;	
	}
	else
	{
		temp -> next = *stack;
		*stack = temp;	
	}
}

void Pop(LinkStack *stack)
{
	if (StackEmpty(stack)) {
		printf("栈为空栈，出栈失败!\n");
		return;	
	}

	PtrToNode firstCell = *stack;
	*stack = firstCell -> next;
	free(firstCell);
	firstCell = NULL;
}

void show(LinkStack *stack)
{
	PtrToNode temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp -> data);	
		temp = temp -> next;
	}
	printf("\n");
}
