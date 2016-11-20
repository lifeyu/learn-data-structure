#include "seqlist.h"

void main()
{
	List list;
	InitList(&list);

	ElemType item;
	ElemType temp;
	int pos;
	boolean flag;
	int select = 1;
	while (select)
	{
		printf("**********************************************\n");	
		printf("* [1]  push_front          [2]  push_back    *\n");
		printf("* [3]  pop_front           [4]  pop_back     *\n");
		printf("* [5]  insert_pos          [6]  delete_pos   *\n");	
		printf("* [7]  delete_val                            *\n");
		printf("* [8]  find_pos            [9]  find_val     *\n");
		printf("* [10] prior_elem          [11] next_elem    *\n");
		printf("* [12] length              [13] empty        *\n");
		printf("* [14] clear               [15] destroy      *\n");
		printf("* [16] sort                [17] resver       *\n");
		printf("* [18] show_list                             *\n");	
		printf("* [0]  quit                                  *\n");	
		printf("**********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入要插入的数据 (-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				push_front(&list, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据 (-1结束):>");
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
			printf("请输入要删除的数据位置:>");
			scanf("%d", &pos);
			flag = ListDelete(&list, pos, &item);
			if (flag) printf("删除成功, 删除位置 %d 的值为 %d.\n", pos, item);
			break;
		case 7:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			delete_val(&list, item);
			break;
		case 8:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			flag = GetElem(&list, pos, &item);
			if (flag)
				printf("查找成功, 查找位置 %d 的元素为 %d.\n", pos, item);
			else
				printf("查找位置 %d 的数据失败!\n", pos);
			break;
		case 9:
			printf("请输入要查找的数据:>");
			scanf("%d", &item);
			pos = find(&list, item);
			if (pos == -1)
				printf("查找的数据 %d 在顺序表中不存在.\n", item);
			else 
				printf("查找的数据 %d 在顺序表中的位置为 %d.\n", item, pos);
			break;
		case 10:
			printf("请输入要查找前驱的元素:>");
			scanf("%d", &item);
			flag = PriorElem(&list, item, &temp);
			if (flag) printf("查找的元素 %d 的前驱为 %d.\n", item, temp);
			break;
		case 11:
			printf("请输入要查找后继的元素:>");
			scanf("%d", &item);
			flag = NextElem(&list, item, &temp);
			if (flag) printf("查找的元素 %d 的后继为 %d.\n", item, temp);
			break;
		case 12:
			printf("顺序表的当前长度为: %d\n", ListLength(&list));
			break;
		case 13:
			flag = ListEmpty(&list);
			if (flag) 
				printf("顺序表为空表!\n");
			else 
				printf("顺序表不为空!\n");
			break;
		case 14:
			ClearList(&list);
			break;
		case 15:
			DestroyList(&list);
			break;
		case 16:
			sort(&list);
			break;
		case 17:
			resver(&list);
			break;
		case 18:
			show_list(&list);
			break;
		default:
			printf("输入的选择错误, 请重新输入!\n");
			break;
		}
	}
}
