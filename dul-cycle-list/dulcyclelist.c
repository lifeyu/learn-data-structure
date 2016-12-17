#include "dulcyclelist.h"

void InitList(DulCycleList *list)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);

	list -> first = list -> last = temp;
	list -> first -> prior = list -> last;
	list -> last -> next = list -> first;
	list -> size = 0;
}

void DestroyList(DulCycleList *list)
{
	ClearList(list);
	free(list -> first);
	list -> first = list -> last = NULL;
}

void ClearList(DulCycleList *list)
{
	if (list -> size == 0) return;

	Position temp = list -> first -> next;
	while (temp != list -> first)
	{
		temp -> next -> prior = list -> first;
		temp -> prior -> next = temp -> next;	
		free(temp);
		temp = list -> first -> next;
	}

	list -> last = list -> first;
	list -> size = 0;
}

boolean ListEmpty(DulCycleList *list)
{
	return list -> size == 0;
}

int ListLength(DulCycleList *list)
{
	return list -> size;
}

Position GetElem(DulCycleList *list, int pos)
{
	if (pos < 0 || pos > list -> size) return NULL;
	
	Position n = NULL;		// 返回查找指定位置的结点
	Position temp = list -> first -> next;
	for (int i = 0; i < list -> size; i++)
	{
		if (i == pos)
		{
			n = temp;
			break;	
		}	

		temp = temp -> next;
	}

	return n;
}

Position PriorElem(DulCycleList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position prior = list -> first -> next;
	while (prior != list -> first && prior -> data != elem)
	{
		prior = prior -> next;	
	}

	if (prior == list -> first) return NULL;

	return prior -> prior;
}

Position NextElem(DulCycleList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position next = list -> first -> next;
	while (next != list -> first && next -> data != elem)
	{
		next = next -> next;	
	}

	if (next == list -> first) return NULL;

	return next -> next;
}

void ListInsert(DulCycleList *list, int pos, ElemType elem)
{
	if (pos == 0)
	{
		push_front(list, elem);
		return;
	}

	if (pos == list -> size)
	{
		push_back(list, elem);
		return;	
	}

	Position current = GetElem(list, pos);

	if (current == NULL)
	{
		printf("插入的位置错误 !\n");	
		return;
	}

	Position temp = malloc ( sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = current;
	temp -> prior = current -> prior;
	temp -> next -> prior = temp;
	temp -> prior -> next = temp;	
	list -> size++;
}

void ListDelete(DulCycleList *list, int pos)
{
	if (pos == 0)
	{
		pop_front(list);
		return;	
	}

	if (pos == list -> size)
	{
		pop_back(list);
		return;	
	}

	Position current = GetElem(list, pos);

	if (current == NULL)
	{
		printf("删除的位置不存在，不能删除 !\n");	
		return;
	}

	current -> prior -> next = current -> next;
	current -> next -> prior = current -> prior;
	free(current);
	list -> size--;
}

void show_list(DulCycleList *list)
{
	Position temp = list -> first -> next;
	while (temp != list -> first)
	{
		printf("%d-->", temp -> data);	
		temp = temp -> next;
	}
	printf("Nul.\n");
}

void push_front(DulCycleList *list, ElemType elem)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = list -> first -> next;
	temp -> next -> prior = temp;
	temp -> prior = list -> first;
	list -> first -> next = temp;

	if (list -> first == list -> last) list -> last = temp;

	list -> size++;
}

void push_back(DulCycleList *list, ElemType elem)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = list -> last -> next;
	temp -> next -> prior = temp;
	temp -> prior = list -> last;
	list -> last -> next = temp;
	list -> last = temp;

	list -> size++;
}

void pop_front(DulCycleList *list)
{
	if (list -> size == 0)
	{
		printf("双向循环链表为空，头部删除错误 !\n");
		return;	
	}

	Position temp = list -> first -> next;
	temp -> next -> prior = temp -> prior;
	temp -> prior -> next = temp -> next;
	if (list -> size == 1) list -> last = list -> first;
	
	free(temp);

	list -> size--;
}

void pop_back(DulCycleList *list)
{
	if (list -> size == 0)
	{
		printf("双向循环链表为空，尾部删除错误 !\n");	
		return;
	}

	Position temp = list -> last;
	list -> last = list -> last -> prior;
	
	temp -> next -> prior = temp -> prior;
	temp -> prior -> next = temp -> next;
	free(temp);
	list -> size--;
}

void insert_val(DulCycleList *list, ElemType elem)
{
	Position p = list -> first;
	while (p -> next != list -> last && p -> next -> data < elem)
	{
		p = p -> next;
	}

	if (p -> next == list -> last && p -> next -> data < elem)
	{
		push_back(list, elem);	
	}	
	else
	{
		Position temp = malloc ( sizeof (struct Node));	
		assert(temp != NULL);
		temp -> data = elem;

		temp -> next = p -> next;
		temp -> next -> prior = temp;
		temp -> prior = p;
		p -> next = temp;
		list -> size++;
	}
}

void delete_val(DulCycleList *list, ElemType elem)
{
	if (list -> size == 0)
	{
		printf("删除失败, 双向循环链表为空 !\n");
		return;	
	}

	Position temp = find_val(list, elem);

	if (temp == NULL)
	{
		printf("删除失败，双向链表不存在与输入数据对应的结点. \n");	
		return;
	}

	if (temp == list -> last)
	{
		pop_back(list);	
	}
	else
	{
		temp -> next -> prior = temp -> prior;
		temp -> prior -> next = temp -> next;	
		free(temp);
		list -> size--;
	}
}

Position find_val(DulCycleList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position temp = list -> first -> next;
	while (temp != list -> first && temp -> data != elem)
	{
		temp = temp -> next;	
	}

	if (temp == list -> first) return NULL;

	return temp;
}

void sort(DulCycleList *list)
{
	if (list -> size < 2) return;

	Position s = list -> first -> next;
	Position q = s -> next;

	list -> last -> next = NULL;
	list -> last = s;
	list -> last -> next = list -> first;
	list -> first -> prior = s;

	while (q != NULL)
	{
		s = q;
		q = q -> next;	

		Position p = list -> first;
		while (p -> next != list -> first && p -> next -> data < s -> data)
		{
			p = p -> next;	
		}

		if (p -> next == list -> last && p -> next -> data < s -> data)
		{
			s -> next = list -> last -> next;
			s -> next -> prior = s;
			s -> prior = list -> last;
			list -> last -> next = s;
			list -> last = s;	
		}
		else
		{
			s -> next = p -> next;
			s -> next -> prior = s;
			s -> prior = p;
			p -> next = s;	
		}
	}
}

void resver(DulCycleList *list)
{
	if (list -> size < 2) return;

	Position s = list -> first -> next;
	Position q = s -> next;

	list -> last -> next = NULL;
	list -> last = s;
	list -> last -> next = list -> first;
	list -> first -> prior = list -> last;

	while (q != NULL)
	{
		s = q;
		q = q -> next;

		s -> next = list -> first -> next;
		s -> next -> prior = s;
		s -> prior = list -> first;
		list -> first -> next = s;
	}
}
