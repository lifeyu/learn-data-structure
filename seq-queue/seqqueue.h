#ifndef __SEQ_QUEUE_H__
#define __SEQ_QUEUE_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef _Bool boolean;
typedef int ElemType;				// 顺序队列存储值的类型

#define MAXSIZE 8				// 队列最大分配空间

typedef struct SeqQueue {			// 顺序队列的结构
	ElemType *base;				// 初始化动态分配空间
	int 	 front;				// 头指针
	int 	 rear;				// 尾指针
} SeqQueue;

void InitQueue(SeqQueue *queue);

void DestroyQueue(SeqQueue *queue);

void ClearQueue(SeqQueue *queue);

/**
 * 如果队列为空，则返回 true；否则返回 false
 */
boolean QueueEmpty(SeqQueue *queue);

int QueueLength(SeqQueue *queue);

/**
 * 获取队列的队头元素
 *
 * return boolean:true.获取成功   false.获取失败
 */
boolean GetHead(SeqQueue *queue, ElemType *elem);

/**
 * 插入元素到队列中
 */
void EnQueue(SeqQueue *queue, ElemType elem);

/**
 * 若队列不为空，删除队头元素，且将元素赋给 elem，返回 true；否则返回 false
 */
boolean DeQueue(SeqQueue *queue, ElemType *elem);

void show(SeqQueue *queue);


#endif	// __SEQ_QUEUE_H__
