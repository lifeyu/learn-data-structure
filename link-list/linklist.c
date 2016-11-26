#include "linklist.h"


void InitList(LinkList *list)
{
	list -> first = list -> last = malloc(sizeof (struct Node));
	assert(list -> first != NULL);
	list -> first -> next = NULL;
	list -> size = 0;
}

void DestroyList(LinkList *list)
{
	ClearList(list);
	free(list -> first);
	list -> first = list -> last = NULL;
}

void ClearList(LinkList *list)
{
	if (list -> size == 0) return;

	Position temp = list -> first -> next;
	while (temp != NULL)
	{
		list -> first -> next = temp -> next;
		free(temp);
		temp = list -> first -> next;
	}

	list -> last = list -> first;
	list -> size = 0;
}

boolean ListEmpty(LinkList *list)
{
	return list -> size == 0;
}

int ListLength(LinkList *list)
{
	return list -> size;
}

Position GetElem(LinkList *list, int pos)
{
	if (pos < 0 || pos > list -> size) return NULL;	

	Position n = NULL;			// 返回查找指定位置的节点
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

Position GetElemPrior(LinkList *list, int pos)
{
	if (pos < 0 || pos > list -> size) return NULL;	

	Position prior = NULL;			// 返回查找指定位置的前一个节点
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

Position PriorElem(LinkList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position prior = list -> first -> next;

	// check get elem is first elem
	if (prior != NULL && prior -> data == elem) return NULL;

	while (prior != NULL && prior -> next != NULL && prior -> next -> data != elem)
	{
		prior = prior -> next;	
	}

	return prior;
}

Position NextElem(LinkList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position next = list -> first -> next;
	while (next != NULL && next -> data != elem)
	{
		next = next -> next;	
	}

	return next != NULL ? next -> next : NULL;
}

void ListInsert(LinkList *list, int pos, ElemType elem)
{
	// check is push front?
	if (pos == 0) 
	{
		push_front(list, elem);
		return;
	}

	// check is push back ?
	if (pos == list -> size)
	{
		push_back(list, elem);
		return;	
	}

	Position prior;
	prior = GetElemPrior(list, pos);

	if (prior == NULL)
	{
		printf("插入的位置不存在, 不能插入 !\n");	
		return;
	}	

	Position in = malloc (sizeof (struct Node));
	assert(in != NULL);
	in -> data = elem;
	in -> next = prior -> next;
	prior -> next = in;
	list -> size++;
}

void ListDelete(LinkList *list, int pos)
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

	Position prior;
	prior = GetElemPrior(list, pos);

	if (prior == NULL)
	{
		printf("删除的位置不存在, 不能删除 !\n");	
		return;
	}

	Position temp = prior -> next;
	prior -> next = temp -> next;	
	free(temp);
	list -> size--;
}

void show_list(LinkList *list)
{
	Position pos = list -> first -> next;	
	while (pos != NULL)
	{
		printf("%d-->", pos -> data);	
		pos = pos -> next;
	}
	printf("Null.\n");
}

void push_front(LinkList *list, ElemType elem)
{
	Position temp = malloc(sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = list -> first -> next;
	list -> first -> next = temp;
	if (list -> size == 0) list -> last = temp;
	list -> size++;
}

void push_back(LinkList *list, ElemType elem)
{
	Position temp = malloc(sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;
	temp -> next = NULL;

	list -> last -> next = temp;		
	list -> last = temp;
	list -> size++;
}

void pop_front(LinkList *list)
{
	if (list -> size == 0)
	{
		printf("单链表为空, 头部删除错误 !\n");	
		return;
	}

	Position temp = list -> first -> next;
	list -> first -> next = temp -> next;
	free(temp);
	if (list -> size == 1) list -> last = list -> first;
	list -> size--;
}

void pop_back(LinkList *list)
{
	if (list -> size == 0)
	{
		printf("单链表为空, 尾部删除错误 !\n");	
		return;
	}
	
	Position pos = list -> first;
	while (pos -> next != list -> last)
	{
		pos = pos -> next;	
	}	
	
	free(list -> last);
	list -> last = pos;
	list -> last -> next = NULL;
	list -> size--;
}

void insert_val(LinkList *list, ElemType elem)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;
	temp -> next = NULL;

	Position pos = list -> first;
	while (pos -> next != NULL && pos -> next -> data < elem)
	{
		pos = pos -> next;
	}
	
	if (pos -> next == NULL) list -> last = pos;

	temp -> next = pos -> next;
	pos -> next = temp;
	list -> size++;
}

void delete_val(LinkList *list, ElemType elem)
{
	if (list -> size == 0)
	{
		printf("删除失败, 单链表为空 !\n");	
		return;
	}
	
	Position temp = find_val(list, elem);	
	if (temp == NULL)
	{
		printf("删除失败, 单链表不存在与输入数据对应的节点.\n");	
		return;
	}
	
	/*Position prior;
	prior = PriorElem(list, elem);
	// not prior, special treatment.
	if (prior == NULL)
	{
		if (list -> size == 1)
		{
			free(temp);
			list -> last = NULL;
		} else {
			list -> first -> next = temp -> next;	
			free(temp);
		}
	} 
	else
	{
		Position t;
		t = prior -> next;
		prior -> next = t -> next;
		free(t);
	}
	list -> size--;*/

	if (temp == list -> last)
	{
		pop_back(list);	
	}
	// if temp -> next equal last, free() after list -> last is free
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

Position find_val(LinkList *list, ElemType elem)
{
	/*if (list -> size == 0)
	{
		printf("单链表为空, 查找失败 !\n");	
		return NULL;
	}
	
	Position fi = NULL;
	Position pos = list -> first;
	while (pos -> next != NULL)
	{
		if (pos -> next -> data == elem)
		{
			fi = pos -> next;	
			break;
		}	
	}	

	return fi;*/

	if (list -> size == 0) return NULL;

	Position p = list -> first -> next;
	while (p != NULL && p -> data != elem)
	{
		p = p -> next;	
	}

	return p;
}

void sort(LinkList *list)
{
	if (list -> size == 0 || list -> size == 1) return;
	
	Position s = list -> first -> next;
	Position q = s -> next;

	list -> last = s;
	list -> last -> next = NULL;

	while (q != NULL)
	{
		s = q;
		q = q -> next;

		Position p = list -> first;
		while (p -> next != NULL && p -> next -> data < s -> data)
		{
			p = p -> next;
		}
		
		if (p -> next == NULL)
		{
			list -> last = s;
		}
		s -> next = p -> next;
		p -> next = s;
	}	
}

void resver(LinkList *list)
{
	if (list -> size == 0 || list -> size == 1) return;	

	Position s = list -> first -> next;
	Position q = s -> next;

	list -> last = s;
	list -> last -> next = NULL;

	while (q != NULL)
	{
		s = q;
		q = q -> next;	

		s -> next = list -> first -> next;
		list -> first -> next = s;
	}
}
