#ifndef __ARRAY_H__
#define __ARRAY_H__

/**
 * 数组的顺序表示
 */

#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef _Bool boolean;
typedef int ElemType;				// 数组存储值的类型

#define MAX_ARRAY_DIM 8				// 数组的最大维数

typedef struct {				// 数组元素结构
	ElemType * base;			// 数组元素基址, 由 InitArray 分配
	int      dim;				// 数组维数
	int      * bounds;			// 数组维界基址, 由 InitArray 分配
	int      * constants;			// 数组映像函数常量基址, 由 InitArray 分配
} Array;



/**
 * 初始化数组
 */
void InitArray(Array *array, int dim, ...);

/**
 * 销毁数组
 */
void DestroyArray(Array *array);

/**
 * 获取数组指定下标的值 
 *
 * @param elem
 * 		元素变量
 */
void Value(Array *array, ElemType *elem, ...);

/**
 * 数组指定下标赋值
 *
 * @param elem
 * 		元素变量
 */
void Assign(Array *array, ElemType elem, ...);



//------------------------------------------------------------------
// 辅助方法
//------------------------------------------------------------------

/**
 * 显示数组
 */
void show(Array *array);

/**
 * 获取数组的长度
 */
int length(Array *array);

/**
 * 若 ap 指示的各下标值合法, 则求出该元素在 array 中的相对地址 off
 *
 * @param ap
 * 		va_list
 * @param off
 * 		相对地址
 * @return boolean: true.查找成功   false.查找失败
 * @see #Value
 * @see #Assign
 */
boolean Locate(Array *array, va_list ap, int *off);

#endif // __ARRAY_H__
