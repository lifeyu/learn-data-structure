#include "array.h"

void InitArray(Array *array, int dim, ...)
{
	// 若维数 dim 和各维长度合法, 则构造相应的数组 array
	if (dim < 1 || dim > MAX_ARRAY_DIM) 
	{
		printf("输入维数不合法, 请重新输入.\n");
		return;
	}		

	array -> dim = dim;
	array -> bounds = (int *) malloc(sizeof(int) * dim); 
	assert(array -> bounds != NULL);

	va_list ap;		// 定义 va_list 变量, 变参	
	// 若各维长度合法, 则存入 array.bounds, 并求出 array 的元素总数 elemtotal
	int elemtotal = 1;
	va_start(ap, dim);	// ap 为 va_list 类型, 为存放变长参数表信息的数组
	for (int i = 0; i < dim; i++)
	{
		array -> bounds[i] = va_arg(ap, int);	
		if (array -> bounds[i] < 0) return;
		elemtotal *= array -> bounds[i];
	}
	va_end(ap);

	array -> base = (ElemType *) malloc(sizeof(ElemType) * elemtotal);
	assert(array -> base != NULL);

	// 求映像函数的常量, 并存入 array -> contains[i - 1], i = 1, ..., dim
	array -> constants = (int *) malloc(sizeof(int) * dim);
	assert(array -> constants != NULL);
	array -> constants[dim - 1] = 1;		// L = 1, 指针增量已元素的大小为单位
	for (int i = dim - 2; i >= 0; i--)
	{
		array -> constants[i] = array -> bounds[i + 1] * array -> constants[i + 1];	
	}

}

void DestroyArray(Array *array)
{
	if (array -> base != NULL)
	{
		free(array -> base);
		array -> base = NULL;	
	}
	if (array -> bounds != NULL)
	{
		free(array -> bounds);
		array -> bounds = NULL;
	}
	if (array -> constants != NULL)
	{
		free(array -> constants);
		array -> constants = NULL;	
	}
}

void Value(Array *array, ElemType *elem, ...)
{
	// array 是 n 维数组, elem 为元素变量, 随后是 n 个下标值
	// 若各下标不越界, 则 elem 赋值为 array 所指的元素值
	int off = 0;
	va_list ap;
	va_start(ap, elem);
	if (!Locate(array, ap, &off)) return;
	* elem = * (array -> base + off);
}

void Assign(Array *array, ElemType elem, ...)
{
	// array 是 n 维数组, elem 为元素变量, 随后是 n 个下标值
	// 若下标不超界, 则将 elem 的值赋给所指定的 array 的元素
	int off = 0;
	va_list ap;
	va_start(ap, elem);
	if (!Locate(array, ap, &off)) return;
	* (array -> base + off) = elem;
}



//------------------------------------------------------------------
// 辅助方法
//------------------------------------------------------------------

void show(Array *array)
{
	int len = length(array);
	if (len == 0) return;

	for (int i = 0; i < len; i++)
	{
		printf("%4d", * (array -> base + i));	
	}	
	printf("\n");
}

int length(Array *array)
{
	if (array -> dim <= 0) return 0;

	int len = 0;
	for (int i = 0; i < array -> dim; i++)
	{
		if (len == 0)
		{
			len = array -> bounds[i];	
		}
		else
		{
			len *= array -> bounds[i];	
		}
	}

	return len;
}

boolean Locate(Array *array, va_list ap, int *off)
{
	for (int i = 0; i < array -> dim; i++)
	{
		int tmp = va_arg(ap, int);	
		if (tmp < 0 || tmp >= array -> bounds[i]) return false;
		* off += array -> constants[i] * tmp;
	}
	
	return true;
}
