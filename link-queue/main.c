#include "linkqueue.h"

void main()
{
	LinkQueue queue;
	InitQueue(&queue);

	int select = 1;
	ElemType item;
	boolean flag;
	while (select)
	{
		printf("*********************************************\n");	
		printf("*  [1]  enqueue           [2]  dequeue      *\n");	
		printf("*  [3]  gethead                             *\n");	
		printf("*  [4]  length            [5]  empty        *\n");	
		printf("*  [6]  clear             [7]  destroy      *\n");	
		printf("*  [8]  show                                *\n");	
		printf("*  [0]  quit                                *\n");	
		printf("*********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入要入队的数据 (-1) 结束:>\n");
			while (scanf("%d", &item), item != -1)
			{
				EnQueue(&queue, item);	
			}
			break;
		case 2:
			flag = DeQueue(&queue, &item);
			if (flag)
				printf("删除元素为 %d.\n", item);
			else
				printf("队列为空，删除失败!\n");
			break;
		case 3:
			flag = GetHead(&queue, &item);
			if (flag) printf("队头元素为 %d.\n", item);
			break;
		case 4:
			printf("队列的长度为 %d.\n", QueueLength(&queue));
			break;
		case 5:
			flag = QueueEmpty(&queue);
			if (flag) printf("队列为空队列.\n");
			break;
		case 6:
			ClearQueue(&queue);
			break;
		case 7:
			DestroyQueue(&queue);
			break;
		case 8:
			show(&queue);
			break;
		default:
			printf("输入的选择错误，请重新输入!\n");
			break;
		}
	}	
}
