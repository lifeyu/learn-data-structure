#ifndef __SEQ_STACK_H__
#define __SEQ_STACK_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef _Bool boolean;
typedef int ElemType;			// 顺序栈存储值的类型

#define EMPTYTOS 0
#define STACK_INIT_SIZE 8

typedef struct SeqStack {			// 顺序栈结构
	ElemType *base;
	int 	 capacity;
	int	 top;
} Stack;

void InitStack(Stack *stack);

void DestroyStack(Stack *stack);

void ClearStack(Stack *stack);

/**
 * 如果栈为空，则返回 true；否则返回 false
 */
boolean StackEmpty(Stack *stack);

int StackLength(Stack *stack);

/**
 * 获取栈顶元素
 *
 * @param elem 返回的栈顶元素
 *
 * return 如果栈为空，则返回 false；否则返回 true
 */
boolean GetTop(Stack *stack, ElemType *elem);

/**
 * 将指定元素压入栈中
 */
void Push(Stack *stack, ElemType elem);

/**
 * 将栈顶元素出栈
 */
void Pop(Stack *stack);


/**
 * 判断栈是否已经满
 *
 * return 如果栈满返回 true，否则返回 false
 */
boolean isFull(Stack *stack);

void show(Stack *stack);


#endif  // __SEQ_STACK_H__
