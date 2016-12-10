#include "singlecyclelist.h"

void InitList(SingleCycleList *list)
{
	list -> first = list -> last = malloc(sizeof (struct Node));
	assert(list -> first != NULL);
	list -> last -> next = list -> first;
	list -> size = 0;	
}

void DestoryList(SingleCycleList *list)
{
	ClearList(list);
	free(list -> first);
	list -> first = list -> last = NULL;
}

void ClearList(SingleCycleList *list)
{
	if (list -> size == 0) return;

	Position temp = list -> first -> next;
	while (temp != list -> first)
	{
		list -> first -> next = temp -> next;
		free(temp);	
		temp = list -> first -> next;
	}
	list -> size = 0;
	list -> last = list -> first;
	list -> last -> next = list -> first;
}

boolean ListEmpty(SingleCycleList *list)
{
	return list -> size == 0;
}

int ListLength(SingleCycleList *list)
{
	return list -> size;
}

Position GetElem(SingleCycleList *list, int pos)
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

Position GetElemPrior(SingleCycleList *list, int pos)
{

	if (pos < 0 || pos > list -> size) return NULL;

	Position prior = NULL;		// 返回查找指定位置的结点
	Position temp = list -> first -> next;
	for (int i = 0; i < list -> size; i++)
	{
		if ((i + 1) == pos && (i + 1) < list -> size)
		{
			prior = temp;	
			break;
		}	
		temp = temp -> next;
	}

	return prior;
}

Position PriorElem(SingleCycleList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position prior = list -> first -> next;

	// check get elem is first elem
	if (prior != NULL && prior -> data == elem) return NULL;

	while (prior -> next != list -> first && prior -> next != NULL && prior -> next -> data != elem)
	{
		prior = prior -> next;	
	}

	if (prior -> next == list -> first) return NULL;

	return prior;
}

Position NextElem(SingleCycleList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position next = list -> first -> next;
	while (next -> next != list -> first && next -> data != elem)
	{
		next = next -> next;	
	}	
	
	if (next -> next == list -> first) return NULL;

	return next != NULL ? next -> next : NULL;
}

void ListInsert(SingleCycleList *list, int pos, ElemType elem)
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

	Position prior = GetElemPrior(list, pos);

	if (prior == NULL)
	{
		printf("插入的位置错误 !\n");	
		return;
	}

	Position temp = malloc(sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = prior -> next;
	prior -> next = temp;
	list -> size++;
}

void ListDelete(SingleCycleList *list, int pos)
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

	Position prior = GetElemPrior(list, pos);

	if (prior == NULL)
	{
		printf("删除的位置不存在，不能删除 !\n");	
		return;
	}

	Position temp = prior -> next;
	prior -> next = temp -> next;
	free(temp);
	list -> size--;
}

void show_list(SingleCycleList *list)
{
	Position temp = list -> first -> next;
	while (temp != list -> first)
	{
		printf("%d-->", temp -> data);	
		temp = temp -> next;
	}
	printf("Nul.\n");
}

void push_front(SingleCycleList *list, ElemType elem)
{
	Position temp = malloc(sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = list -> first -> next;
	list -> first -> next = temp;
	if (list -> first == list -> last)
	{
		list -> last = temp;	
	}	
	list -> size++;
}

void push_back(SingleCycleList *list, ElemType elem)
{
	Position temp = malloc(sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	list -> last -> next = temp;
	list -> last = temp;	
	list -> last -> next = list -> first;
	list -> size++;
}

void pop_front(SingleCycleList *list)
{
	if (list -> size == 0)
	{
		printf("单循环链表为空，头部删除错误!\n");
		return;	
	}	

	Position temp = list -> first -> next;
	list -> first -> next = temp -> next;
	if (list -> size == 1) list -> last = list -> first;
	free(temp);
	list -> size--;
}

void pop_back(SingleCycleList *list)
{
	if (list -> size == 0)
	{
		printf("单循环链表为空，尾部删除错误 !\n");	
		return;
	}

	Position temp = list -> first;
	while (temp -> next !=  list -> last)
	{
		temp = temp -> next;	
	}
	
	free(list -> last);
	list -> last = temp;
	list -> last -> next = list -> first;
	list -> size--;
}

void insert_val(SingleCycleList *list, ElemType elem)
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
		Position temp = malloc(sizeof (struct Node));
		assert(temp != NULL);
		temp -> data = elem;
	
		temp -> next = p -> next;
		p -> next = temp;
		list -> size++;		
	}
}

void delete_val(SingleCycleList *list, ElemType elem)
{
	if (list -> size == 0)
	{
		printf("删除失败，单循环链表为空 !\n");	
		return;
	}

	Position temp = find_val(list, elem);
	
	if (temp == NULL)
	{
		printf("删除失败，单循环链表不存在与输入数据对应的结点.\n");	
		return;
	}

	if (temp == list -> last)
	{
		pop_back(list);	
	}
	else if (temp -> next == list -> last)
	{
		Position q = temp -> next;	
		temp -> data = q -> data;
		temp -> next = q -> next;
		list -> last = temp;
		free(q);
		list -> size--;
	}
	else
	{
		Position q = temp -> next;
		temp -> data = q -> data;
		temp -> next = q -> next;
		free(q);
		list -> size--;	
	}
}

Position find_val(SingleCycleList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position p = list -> first -> next;
	while (p != list -> first && p -> data != elem)
	{
		p = p -> next;	
	}

	if (p == list -> first) return NULL;

	return p;
}

void sort(SingleCycleList *list)
{
	if (list -> size < 2) return;

	Position temp = list -> first -> next;
	Position p = temp -> next;

	list -> last -> next = NULL;
	list -> last = temp;
	list -> last -> next = list -> first;

	while (p != NULL)
	{
		temp = p;
		p = p -> next;

		Position q = list -> first;
		while (q -> next != list -> last && q -> next -> data < temp -> data)
		{
			q = q -> next;
		}	

		if (q -> next == list -> last && q -> next -> data < temp -> data)
		{
			temp -> next = list -> last -> next;
			list -> last -> next = temp;
			list -> last = temp;	
		}
		else
		{
			temp -> next = q -> next;
			q -> next = temp;	
		}
	}
}

void resver(SingleCycleList *list)
{
	if (list -> size < 2) return;

	Position temp = list -> first -> next;
	Position p = temp -> next;

	list -> last -> next = NULL;
	list -> last = temp;
	list -> last -> next = list -> first;

	while (p != NULL)
	{
		temp = p;
		p = p -> next;

		temp -> next = list -> first -> next;
		list -> first -> next = temp;
	}
}
