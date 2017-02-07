#ifndef __CYCLE_QUEUE_H__
#define __CYCLE_QUEUE_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef _Bool boolean;
typedef int ElemType;				// 循环队列存储值的类型

#define MAXSIZE 8				// 队列最大分配空间

typedef struct CycyleQueue {			// 循环队列的结构
	ElemType *base;				// 初始化动态分配空间
	int 	 front;				// 头指针
	int 	 rear;				// 尾指针
} CycleQueue;

void InitQueue(CycleQueue *queue);

void DestroyQueue(CycleQueue *queue);

void ClearQueue(CycleQueue *queue);

/**
 * 如果队列为空，则返回 true；否则返回 false
 */
boolean QueueEmpty(CycleQueue *queue);

int QueueLength(CycleQueue *queue);

/**
 * 获取队列的队头元素
 *
 * return boolean:true.获取成功   false.获取失败
 */
boolean GetHead(CycleQueue *queue, ElemType *elem);

/**
 * 插入元素到队列中
 */
void EnQueue(CycleQueue *queue, ElemType elem);

/**
 * 若队列不为空，删除队头元素，且将元素赋给 elem，返回 true；否则返回 false
 */
boolean DeQueue(CycleQueue *queue, ElemType *elem);

void show(CycleQueue *queue);


#endif	// __CYCLE_QUEUE_H__
