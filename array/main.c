#include "array.h"

void main()
{
	Array array;

	int select = 1;
	int dim;
	int dimVal;
	int dimAss;
	while (select)
	{
	
		printf("*********************************************\n");	
		printf("*  [1]  init           [2]  value           *\n");	
		printf("*  [3]  assign                              *\n");
		printf("*  [4]  show                                *\n");
		printf("*  [0]  quit                                *\n");
		printf("*********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入创建的维数.\n");
			while (scanf("%d", &dim), dim == -1 || dim > MAX_ARRAY_DIM)
			{
				printf("输入维数不合法, 请重新输入.\n");	
			}
			printf("请输入每个维数的基址.\n");
			int *ap = (int *) malloc(sizeof(int) * dim);
			assert(ap != NULL);
			for (int i = 0; i < dim; i++)
			{
				scanf("%d", &ap[i]);	
			}
			InitArray(&array, dim
					,dim > 0 ? ap[0] : 0 
					,dim > 1 ? ap[1] : 0 
					,dim > 2 ? ap[2] : 0 
					,dim > 3 ? ap[3] : 0 
					,dim > 4 ? ap[4] : 0 
					,dim > 5 ? ap[5] : 0 
					,dim > 6 ? ap[6] : 0 
					,dim > 7 ? ap[7] : 0 
					);
			break;	
		case 2:
			dimVal = array.dim;
			if (dimVal <= 0) 
			{
				printf("数组为空, 请初始化后再获取对于值.\n");
				break;
			}

			printf("请输入获取值的数组下标.\n");
			int *apVal = (int *) malloc(sizeof(int) * dimVal);
			assert(apVal != NULL);
			for (int i = 0; i < dimVal; i++)
			{
				scanf("%d", &apVal[i]);	
			}

			ElemType elemVal = 0;
			Value(&array, &elemVal
					,dim > 0 ? apVal[0] : 0 
					,dim > 1 ? apVal[1] : 0 
					,dim > 2 ? apVal[2] : 0 
					,dim > 3 ? apVal[3] : 0 
					,dim > 4 ? apVal[4] : 0 
					,dim > 5 ? apVal[5] : 0 
					,dim > 6 ? apVal[6] : 0 
					,dim > 7 ? apVal[7] : 0
					);
			if (elemVal > 0)
			{
				printf("数组对应下标值为 %d.\n", elemVal);	
			}
			else
			{
				printf("数组对应下标值为空.\n");	
			}
			break;
		case 3:
			dimAss = array.dim;
			if (dimAss <= 0) 
			{
				printf("数组为空, 请初始化后再进行赋值.\n");
				break;
			}

			printf("请输入赋值值的数组下标.\n");
			int *apAss = (int *) malloc(sizeof(int) * dimAss);
			for (int i = 0; i < dimAss; i++)
			{
				scanf("%d", &apAss[i]);	
			}

			ElemType elemAss;
			printf("请输入要赋的值.\n");
			scanf("%d", &elemAss);
			Assign(&array, elemAss
					,dim > 0 ? apAss[0] : 0 
					,dim > 1 ? apAss[1] : 0 
					,dim > 2 ? apAss[2] : 0 
					,dim > 3 ? apAss[3] : 0 
					,dim > 4 ? apAss[4] : 0 
					,dim > 5 ? apAss[5] : 0 
					,dim > 6 ? apAss[6] : 0 
					,dim > 7 ? apAss[7] : 0 
					);
			break;
		case 4:
			show(&array);
			break;
		default:
			printf("输入的选择错误，请重新输入!\n");
			break;
		}
	}
}
