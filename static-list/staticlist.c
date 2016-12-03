#include "staticlist.h"

void InitList(StaticList list)
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		list[i].next = i + 1;	
	}
	list[MAXSIZE - 1].next = 0;

	list[0].next = -1;
}

int ListLength(const StaticList list)
{
	int i = 0;
	Position pos = list[0].next;
	while (pos != -1)
	{
		i++;
		pos = list[pos].next;	
	}
	return i;
}

Position GetElemPrior(const StaticList list, Position pos)
{
	if (pos < 0 || pos > ListLength(list)) return -1;

	Position i = 0;
	Position prior = list[0].next;
	while (prior != -1 && i != (pos - 1))
	{
		prior = list[prior].next;
		i++;
	}	

	return prior;
}

void ListInsert(StaticList list, Position pos, ElemType elem)
{
	if (pos == 0)
	{
		push_front(list, elem);
		return;	
	}

	// TODO push_back()
	if (pos < 0 || pos > ListLength(list))
	{
		printf("对不起，您插入的位置不存在!\n");	
		return;
	}	
	if (pos == ListLength(list))
	{
		Position i_back = Malloc_SL(list);
		if (i_back == 0)
		{
			printf("链表空间不足不能进行插入!\n");	
			return;
		}
		Position p = list[0].next;
		while (list[p].next != -1)
		{
			p = list[p].next;	
		}	
		
		list[i_back].data = elem;
		list[i_back].next = -1;
		list[p].next = i_back;
		return;
	}

	Position prior = GetElemPrior(list, pos);
	if (prior == -1)
	{
		printf("对不起，您插入的位置不存在!\n");	
		return;
	}
	Position i = Malloc_SL(list);
	if (i == 0)
	{
		printf("链表空间不足不能进行插入!\n");	
		return;
	}

	list[i].data = elem;
	list[i].next = list[prior].next;
	list[prior].next = i;
}

void ListDelete(StaticList list, Position pos)
{
	// 头部删除
	if (pos == 0)
	{
		pop_front(list);	
		return;
	}

	// TODO pop_back()
	if (ListLength(list) == 0) 
	{
		printf("对不起，链表为空，不能进行删除!\n");
		return;
	}
	if (pos == ListLength(list))
	{
		Position p = list[0].next;
		while (list[list[p].next].next != -1)
		{
			p = list[p].next;	
		}	
		Position t = list[p].next;
		list[p].next = -1;
		Free_SL(list, t);	
		return;
	}

	Position prior = GetElemPrior(list, pos);
	if (prior == -1)
	{
		printf("对不起，您删除的位置不存在!\n");	
		return;
	}
	
	Position temp = list[prior].next;
	list[prior].next = list[temp].next;
	Free_SL(list, temp);
}

void show_list(StaticList list)
{
	Position i = list[0].next;
	while (i != -1)
	{
		printf("%d-->", list[i].data);	
		i = list[i].next;
	}
	printf("Nul.\n");
}

void push_front(StaticList list, ElemType elem)
{
	Position i = Malloc_SL(list);
	if (i == 0)
	{
		printf("链表空间不足不能进行插入!\n");	
		return;
	}

	list[i].data = elem;
	/*list[i].next = list[0].next;
	list[0].next = i;*/
	if (list[0].next == -1)
	{
		list[i].next = -1;	
	}
	else
	{
		list[i].next = list[0].next;	
	}
	list[0].next = i;
}

void pop_front(StaticList list)
{
	Position i = list[0].next;
	if (i == -1) return;

	list[0].next = list[i].next;
	Free_SL(list, i);	
}

Position Malloc_SL(StaticList list)
{
	// 若备用空间链表非空，则返回分配节点下标，否则返回 0
	/*int i = list[0].next;
	if (list[0].next) list[0].next = list[i].next;

	return i;*/
	
	int i = list[1].next;
	if (list[1].next != 0) list[1].next = list[i].next;

	return i;
}

void Free_SL(StaticList list, Position p)
{
	// 将下标为 p 的空闲节点回收到备用链表
	/*list[p].next = list[0].next;
	list[0].next = p;*/

	list[p].next = list[1].next;
	list[1].next = p;
}
