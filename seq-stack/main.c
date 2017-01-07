#include "seqstack.h"

void main()
{
	Stack stack;
	InitStack(&stack);

	int select = 1;
	ElemType item;
	boolean flag;
	while (select)
	{
		printf("*********************************************\n");	
		printf("*  [1]  push               [2]  pop         *\n");	
		printf("*  [3]  gettop                              *\n");	
		printf("*  [4]  length             [5]  empty       *\n");	
		printf("*  [6]  clear              [7]  destroy     *\n");	
		printf("*  [8]  show                                *\n");	
		printf("*  [0]  quit                                *\n");	
		printf("*********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入要入栈的数据 (-1) 结束:>\n");
			while (scanf("%d", &item), item != -1)
			{
				Push(&stack, item);	
			}
			break;
		case 2:
			Pop(&stack);
			break;
		case 3:
			flag = GetTop(&stack, &item);
			if (flag) printf("栈顶元素为 %d.\n", item);
			break;
		case 4:
			printf("栈的长度为 %d.\n", StackLength(&stack));
			break;
		case 5:
			flag = StackEmpty(&stack);
			if (flag) printf("栈为空栈.\n");
			break;
		case 6:
			ClearStack(&stack);
			break;
		case 7:
			DestroyStack(&stack);
			break;
		case 8:
			show(&stack);
			break;
		default:
			printf("输入的选择错误，请重新输入!\n");
			break;
		}

	}

}
