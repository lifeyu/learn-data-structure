#include "seqlist.h"

void InitList(List * list)
{
	list -> elem = (ElemType *) malloc(sizeof (ElemType) * LIST_INIT_SIZE);
	if (list -> elem == NULL)
	{
		printf("初始化线性表失败 !\n");	
		return;
	}

	list -> listsize = LIST_INIT_SIZE;
	list -> length = 0;		// 空间长度为0	
}

void DestroyList(List *list)
{
	free(list -> elem);
	list -> elem = NULL;	
	list -> listsize = 0;
	list -> length = 0;
}

void ClearList(List *list)
{
	list -> length = 0;
}

boolean ListEmpty(List *list)
{
	return list -> length == 0;
}

int ListLength(List *list)
{
	return list -> length;
}

boolean GetElem(List *list, int pos, ElemType *elem)
{
	if (pos < 0 || pos >= list -> length)
	{
		printf("查找的位置不合法, 不能查找位置 %d 的数据!\n", pos);	
		return false;
	}

	boolean flag = false;	
	for (int i = 0; i < list -> length; i++)
	{
		if (i == pos)
		{
			*elem = list -> elem[i];
			flag = true;
			break;
		}	
	}

	return flag;
}

boolean PriorElem(List *list, ElemType curElem, ElemType *preElem)
{
	int pos = find(list, curElem);
	if (pos == -1)
	{
		printf("要查找的元素不存在!\n");
		return false;
	}

	if (pos == 0)
	{
		printf("要查找的元素为第一个元素, 不存在前驱!\n");	
		return false;
	}

	*preElem = list -> elem[pos - 1];
	return true;
}

boolean NextElem(List *list, ElemType curElem, ElemType *nextElem)
{
	int pos = find(list, curElem);
	if (pos == -1)
	{
		printf("要查找的元素不存在!\n");	
		return false;
	}

	if (pos == list -> length -1)
	{
		printf("要查找的元素为最后一个元素, 不存在后继!\n");	
		return false;
	}

	*nextElem = list -> elem[pos + 1];
	return true;
}

void ListInsert(List *list, int pos, ElemType elem)
{
	if (pos < 0 || pos > list -> length)
	{
		printf("插入的位置非法, 不能在位置 %d 插入数据!\n", pos);
		return;	
	}

	if (list -> length >= list -> listsize && !AddCapacity(list))
	{
		printf("顺序表的空间已满, %d 不能插入到位置 %d\n", elem, pos);	
		return;
	}	

	for (int i = list -> length; i > pos; i--)
	{
		list -> elem[i] = list -> elem[i - 1];	
	}
	list -> elem[pos] = elem;
	list -> length++;
}


boolean ListDelete(List *list, int pos, ElemType *elem)
{
	if (pos < 0 || pos >= list -> length)
	{
		printf("删除的位置非法, 不能删除位置 %d 的数据!\n", pos);	
		return false;
	}

	*elem = list -> elem[pos];
	for (int i = pos; i < list -> length - 1; i++)
	{
		list -> elem[i] = list -> elem[i + 1];	
	}
	list -> length--;
	return true;
}

void show_list(List *list)
{
	for (int i = 0; i < list -> length; i++)
	{
		printf("%d ", list -> elem[i]);	
	}	
	printf("\n");
}

void push_front(List *list, ElemType elem)
{
	if (list -> length >= list -> listsize && !AddCapacity(list))
	{
		printf("顺序表的空间已满, 不能头部插入数据 %d\n", elem);	
		return;
	}

	for (int i = list -> length; i > 0; i--)
	{
		list -> elem[i] = list -> elem[i - 1];	
	}
	list -> elem[0] = elem;
	list -> length++;

}

void push_back(List *list, ElemType elem)
{
	if (list -> length >= list -> listsize && !AddCapacity(list))
	{
		printf("顺序表的空间已满, 不能尾部插入数据 %d\n", elem);	
		return;
	}

	list -> elem[list -> length] = elem;
	list -> length++;
}

void pop_front(List *list)
{
	if (list -> length <= 0)
	{
		printf("顺序表为空表不能头部删除数据!\n");
		return;
	}	

	for (int i = 0; i < list -> length - 1; i++)
	{
		list -> elem[i] = list -> elem[i + 1];	
	}
	list -> length --;	
}

void pop_back(List *list)
{
	if (list -> length <= 0)
	{
		printf("顺序表为空表不能尾部删除数据!\n");
		return;
	}	

	list -> length--;
}

void delete_val(List *list, ElemType elem)
{
	int pos = find(list, elem);
	if (pos == -1)
		printf("要删除的数据不存在!\n");
	else 
	{
		ElemType temp;
		boolean flag = ListDelete(list, pos, &temp);
		if (flag) printf("删除成功, 删除值 %d 的位置为 %d.\n", temp, pos);
	}
}

int find(List *list, ElemType elem)
{
	for (int i = 0; i < list -> length; i++)
	{
		if (list -> elem[i] == elem) return i;	
	}

	return -1;
}

void sort(List *list)
{
	for (int i = 0; i < list -> length - 1; i++)
	{
		for (int j = 0; j < list -> length - i - 1; j++) {
			if (list -> elem[j] > list -> elem[j + 1])
			{
				ElemType temp = list -> elem[j];
				list -> elem[j] = list -> elem[j + 1];
				list -> elem[j + 1] = temp;	
			}			
		}	
	}
}

void resver(List *list)
{
	if (list -> length == 0 || list -> length == 1) return;

	int low = 0;
	int high = list -> length - 1;
	ElemType temp;
	while (low < high)
	{
		temp = list -> elem[low];
		list -> elem[low] = list -> elem[high];
		list -> elem[high] = temp;

		low++;
		high--;	
	}
}

void MergeList(List *la, List *lb, List *lc)
{
	lc -> listsize = la -> length + lb -> length;
	lc -> elem = (ElemType *) malloc (sizeof (ElemType) * lc -> listsize);
	if (!lc -> elem) return;

	int ia = 0;
	int ib = 0;
	int ic = 0;	

	while (ia < la -> length && ib < lb -> length)
	{
		if (la -> elem[ia] < lb -> elem[ib])
			lc -> elem[ic++] = la -> elem[ia++];	
		else 
			lc -> elem[ic++] = lb -> elem[ib++];
	}

	// 以下处理 la 与 lb 的顺序表大小不一致的问题
	while (ia < la -> length) lc -> elem[ic++] = la -> elem[ia++];

	while (ib < lb -> length) lc -> elem[ic++] = lb -> elem[ib++];

	lc -> length = la -> length + lb -> length;
}

boolean AddCapacity(List *list)
{
	ElemType *newbase = (ElemType *) realloc (list -> elem, 
			sizeof (ElemType) * (list -> listsize + LISTINCREMENT));
	if (newbase == NULL)
	{
		printf("增配空间失败, 内存不足.\n");
		return false;	
	}
	list -> elem = newbase;
	list -> listsize += LISTINCREMENT;
	return true;
}

