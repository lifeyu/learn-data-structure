#include "seqstack.h"

void InitStack(Stack *stack)
{
	//stack = malloc (sizeof (struct SeqStack));
	//assert(stack != NULL);

	stack -> base  = (ElemType *) malloc (sizeof (ElemType) * STACK_INIT_SIZE);
	assert(stack -> base != NULL);
	
	stack -> capacity = STACK_INIT_SIZE;
	stack -> top = EMPTYTOS;
}

void DestroyStack(Stack *stack)
{
	if (stack == NULL) return;

	free(stack -> base);
	stack -> base = NULL;
	stack -> capacity = 0;
	stack -> top = EMPTYTOS;
}

void ClearStack(Stack *stack)
{
	stack -> top = EMPTYTOS;
}

boolean StackEmpty(Stack *stack)
{
	return stack -> top == EMPTYTOS;
}

int StackLength(Stack *stack)
{
	return stack -> top;
}

boolean GetTop(Stack *stack, ElemType *elem)
{
	if (StackEmpty(stack))
	{
		printf("栈空间已空，不能取栈顶元素.\n");	
		return false;
	}

	*elem = stack -> base[stack -> top - 1];

	return true;
}

void Push(Stack *stack, ElemType elem)
{
	if (isFull(stack))
	{
		printf("栈空间已满，%d 不能入栈.\n", elem);	
		return;
	}	
	
	stack -> base[stack -> top++] = elem;
}

void Pop(Stack *stack)
{
	if (StackEmpty(stack))
	{
		printf("栈空间已空，不能入栈.\n");	
		return;
	}

	stack -> top--;
}

boolean isFull(Stack *stack)
{
	return stack -> top == stack -> capacity - 1;
}

void show(Stack *stack)
{

	if (StackEmpty(stack)) 
	{
		printf("栈为空栈.\n");
		return;	
	}

	for (int i = stack -> top - 1; i >= 0; i--)
	{
		printf("%d\n", stack -> base[i]);	
	}	
	printf("\n");
	
}
