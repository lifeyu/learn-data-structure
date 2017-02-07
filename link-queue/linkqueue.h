#ifndef __LINK_QUEUE_H__
#define __LINK_QUEUE_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef _Bool boolean;
typedef int ElemType;				// 链式队列存储值的类型

typedef struct QueueNode {			// 队列的结点结构
	ElemType 	 data;
	struct QueueNode *next;
} QueueNode;

typedef struct LinkQueue {			// 链式队列的结构：包括头结点，尾结点
	QueueNode *front;
	QueueNode *tail;
} LinkQueue;

void InitQueue(LinkQueue *queue);

void DestroyQueue(LinkQueue *queue);

void ClearQueue(LinkQueue *queue);

/**
 * 如果队列为空，则返回 true；否则返回 false
 */
boolean QueueEmpty(LinkQueue *queue);

int QueueLength(LinkQueue *queue);

/**
 * 获取队列的队头元素
 *
 * return boolean:true.获取成功   false.获取失败
 */
boolean GetHead(LinkQueue *queue, ElemType *elem);

/**
 * 插入元素到队列中
 */
void EnQueue(LinkQueue *queue, ElemType elem);

/**
 * 若队列不为空，删除队头元素，且将元素赋给 elem，返回 true；否则返回 false
 */
boolean DeQueue(LinkQueue *queue, ElemType *elem);

void show(LinkQueue *queue);


#endif	// __LINK_QUEUE_H__
