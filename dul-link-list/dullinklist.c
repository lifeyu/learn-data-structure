#include "dullinklist.h"

void InitList(DulLinkList *list)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);

	list -> first = list -> last = temp;
	list -> last -> next = NULL;
	list -> first -> prior = NULL;
	list -> size = 0;
}

void DestroyList(DulLinkList *list)
{
	ClearList(list);
	free(list -> first);
	list -> first = list -> last = NULL;
}

void ClearList(DulLinkList *list)
{
	if (list -> size == 0) return;

	Position temp = list -> first -> next;
	while (temp != NULL)
	{
		if (temp == list -> last)
		{
			list -> last = list -> first;
			list -> last -> next = NULL;	
		}
		else
		{
			temp -> next -> prior = list -> first;
			list -> first -> next = temp -> next;		
		}
		free(temp);
		temp = list -> first -> next;
	}

	list -> size = 0;
}

boolean ListEmpty(DulLinkList *list)
{
	return list -> size == 0;
}

int ListLength(DulLinkList *list)
{
	return list -> size;
}

Position GetElem(DulLinkList *list, int pos)
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

Position PriorElem(DulLinkList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position prior = list -> first -> next;
	while (prior != NULL && prior -> data != elem)
	{
		prior = prior -> next;	
	}

	return prior != NULL ? prior -> prior : NULL;
}

Position NextElem(DulLinkList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position next = list -> first -> next;
	while (next != NULL && next -> data != elem)
	{
		next = next -> next;	
	}
	
	return next != NULL ? next -> next : NULL;
}

void ListInsert(DulLinkList *list, int pos, ElemType elem)
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

	Position temp = malloc( sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> next = current;
	temp -> prior = current -> prior;
	current -> prior -> next = temp;
	current -> prior = temp;
	list -> size++;
}

void ListDelete(DulLinkList *list, int pos)
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

void show_list(DulLinkList *list)
{
	Position temp = list -> first -> next;
	while (temp != NULL)
	{
		printf("%d-->", temp -> data);	
		temp = temp -> next;
	}
	printf("Nul.\n");
}

void push_front(DulLinkList *list, ElemType elem)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	if (list -> first == list -> last)
	{
		temp -> prior = list -> first;
		list -> first -> next = temp;
		list -> last = temp;
		temp -> next = NULL;	// not necessary
	}
	else
	{
		temp -> next = list -> first -> next;
		temp -> next -> prior = temp;
		temp -> prior = list -> first;	
		list -> first -> next = temp;
	}

	list -> size++;
}

void push_back(DulLinkList *list, ElemType elem)
{
	Position temp = malloc (sizeof (struct Node));
	assert(temp != NULL);
	temp -> data = elem;

	temp -> prior = list -> last;
	list -> last -> next = temp;
	list -> last = temp;

	list -> size++;
}

void pop_front(DulLinkList *list)
{
	if (list -> size == 0)
	{
		printf("双向链表为空, 头部删除错误 !\n");
		return;
	}	

	Position temp = list -> first -> next;

	if (list -> first -> next == list -> last)
	{
		list -> last = list -> first;
		list -> last -> next = NULL;	
	}
	else
	{
		list -> first -> next = temp -> next;
		temp -> next -> prior = list -> first;	
	}

	free(temp);

	list -> size--;
}

void pop_back(DulLinkList *list)
{
	if (list -> size == 0)
	{
		printf("双向链表为空, 尾部删除错误 !\n");	
		return;
	}

	// 可以采用这种方法
	//Position temp = list -> last;
	//list -> last = temp -> prior;
	//list -> last -> next = NULL;
	//free(temp);
	
	Position temp = list -> first;
	while (temp -> next != list -> last)
	{
		temp = temp -> next;	
	}

	free(list -> last);
	list -> last = temp;
	list -> last -> next = NULL;
	list -> size--;
}

void insert_val(DulLinkList *list, ElemType elem)
{
	Position p = list -> first;
	while (p -> next != NULL && p -> next -> data < elem)
	{
		p = p -> next;	
	}	

	if (p -> next == NULL)
	{
		push_back(list, elem);	
	}
	else
	{
		Position temp = malloc( sizeof (struct Node));
		assert(temp != NULL);	
		temp -> data = elem;

		temp -> next = p -> next;
		temp -> next -> prior = temp;
		temp -> prior = p;
		p -> next = temp;
		list -> size++;
	}
}

void delete_val(DulLinkList *list, ElemType elem)
{
	if (list -> size == 0)
	{
		printf("删除失败，双向链表为空 !\n");
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
		list -> last = temp -> prior;
		list -> last -> next = NULL;
	}
	else
	{
		temp -> next -> prior = temp -> prior;
		temp -> prior -> next  = temp -> next;	
	}

	free(temp);
	list -> size--;
}

Position find_val(DulLinkList *list, ElemType elem)
{
	if (list -> size == 0) return NULL;

	Position temp = list -> first -> next;
	while (temp != NULL && temp -> data != elem)
	{
		temp = temp -> next;	
	}

	return temp;
}

void sort(DulLinkList *list)
{
	if (list -> size < 2) return;

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
			s -> next = NULL;
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

void resver(DulLinkList *list)
{
	if (list -> size < 2) return;

	Position s = list -> first -> next;
	Position q = s -> next;

	list -> last = s;
	list -> last -> next = NULL;

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
