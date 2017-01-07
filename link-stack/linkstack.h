#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef _Bool boolean;
typedef int ElemType;			// 链式栈存储值的类型

struct Node;				// 链式栈结点结构

typedef struct Node *PtrToNode;
typedef PtrToNode LinkStack;		// 链式栈结构

void InitStack(LinkStack *stack);

void DestroyStack(LinkStack *stack);

void ClearStack(LinkStack *stack);

/**
 * 如果栈为空，则返回 true；否则返回 false
 */
boolean StackEmpty(LinkStack *stack);

int StackLength(LinkStack *stack);

/**
 * 获取栈顶元素
 *
 * @param elem 返回的栈顶元素
 *
 * return 如果栈为空，则返回 false；否则返回 true
 */
boolean GetTop(LinkStack *stack, ElemType *elem);

/**
 * 将指定元素压入栈中
 */
void Push(LinkStack *stack, ElemType elem);

/**
 * 将栈顶元素出栈
 */
void Pop(LinkStack *stack);

void show(LinkStack *stack);

struct Node {
	ElemType	data;
	PtrToNode	next; 
};


#endif  // __LINK_STACK_H__
