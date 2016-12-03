#include "staticlist.h"

void main()
{
	StaticList list;
	InitList(list);
	
	ElemType item;
	Position pos;
	int select = 1;
	while (select)
	{
		printf("*********************************************\n");	
		printf("* [1] push_front          [2] pop_front     *\n");
		printf("* [3] insert_pos          [4] delete_pos    *\n");
		printf("* [5] show_list                             *\n");
		printf("* [0] quit                                  *\n");
		printf("*********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入要插入的数据 (-1) 结束:>");
			while (scanf("%d", &item), item != -1)
			{
				push_front(list, item);
			}
			break;
		case 2:
			pop_front(list);
			break;
		case 3:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			ListInsert(list, pos, item);
			break;
		case 4:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			ListDelete(list, pos);
			break;
		case 5:
			show_list(list);
			break;
		default:
			printf("输入的选择错误，请重新输入!\n");
			break;	
		}
	}
}
