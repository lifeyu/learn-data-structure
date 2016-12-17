#include "dulcyclelist.h"

void main()
{
	DulCycleList list;
	InitList(&list);

	int select = 1;
	ElemType item;
	int pos;
	Position elem;
	boolean flag;
	while (select)
	{
		printf("*********************************************\n");	
		printf("  [1]  push_front          [2]  push_back    \n");	
		printf("  [3]  pop_front           [4]  pop_back     \n");	
		printf("  [5]  insert_pos          [6]  insert_val   \n");	
		printf("  [7]  delete_pos          [8]  delete_val   \n");	
		printf("  [9]  find_pos            [10] find_val     \n");	
		printf("  [11] prior_elem          [12] next_elem    \n");	
		printf("  [13] length              [14] empty        \n");	
		printf("  [15] clear               [16] destroy      \n");	
		printf("  [17] sort                [18] resver       \n");	
		printf("  [19] show_list                             \n");	
		printf("  [0]  quit                                  \n");	
		printf("*********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入要插入的数据 (-1) 结束:>\n");
			while (scanf("%d", &item), item != -1)
			{
				push_front(&list, item);	
			}
			break;	
		case 2:
			printf("请输入要插入的数据 (-1) 结束:>\n");
			while (scanf("%d", &item), item != -1)
			{
				push_back(&list, item);	
			}
			break;
		case 3:
			pop_front(&list);
			break;
		case 4:
			pop_back(&list);
			break;
		case 5:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			ListInsert(&list, pos, item);
			break;
		case 6:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			insert_val(&list, item);
			break;
		case 7:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			ListDelete(&list, pos);
			break;
		case 8:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			delete_val(&list, item);
			break;
		case 9:
			printf("请输入要查找数据的位置:>");
			scanf("%d", &pos);
			elem = GetElem(&list, pos);
			if (elem != NULL)
				printf("查找位置 %d 的数据值为 %d\n", pos, elem -> data);			
			else
				printf("查找位置 %d 的数据不存在 !\n", pos);
			break;
		case 10:
			printf("请输入要查找的数据:>");
			scanf("%d", &item);
			elem = find_val(&list, item);
			if (elem == NULL) printf("查找的数据在双向循环链表中不存在 !\n");
			break;
		case 11:
			printf("请输入要查找前驱的数据:>");
			scanf("%d", &item);
			elem = PriorElem(&list, item);
			if (elem != NULL)
				printf("查找数据的前驱值为：%d.\n", elem -> data);
			else
				printf("查找的数据不存在前驱.\n");
			break;
		case 12:
			printf("请输入要查找后继的数据:>");
			scanf("%d", &item);
			elem = NextElem(&list, item);
			if (elem != NULL)
				printf("查找数据的后继值为：%d.\n", elem -> data);
			else
				printf("查找的数据不存在后继.\n");
			break;
		case 13:
			printf("双向循环链表的长度为 %d.\n", ListLength(&list));
			break;
		case 14:
			flag = ListEmpty(&list);
			if (flag) printf("双向循环链表为空表 !\n");
			break;
		case 15:
			ClearList(&list);
			break;
		case 16:
			DestroyList(&list);
			break;
		case 17:
			sort(&list);
			break;
		case 18:
			resver(&list);
			break;
		case 19:
			show_list(&list);
			break;
		}
	}
}
