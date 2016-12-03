#ifndef __STATICLIST_H__
#define __STATICLIST_H__


#include <stdio.h>

// ------ 线性表的静态链表存储结构 ------

#define MAXSIZE 10		// 链表的最大长度

typedef int ElemType;

typedef int PtrToNode;
//typedef PtrToNode StaticList;
typedef PtrToNode Position;

// 静态链表节点存储结构
typedef struct {
	ElemType data;
	Position next;
} Node;

// 静态链表当前理解下包括以下
// 1. StaticList[0] 为头结点，不需要存储备用结点
// 2. 
// 	StaticList[0] 为头结点
// 	StaticList[1] 存储备用结点的地址 (即静态链表还剩余多少空间结点可用，若为 0 表示静态链表已满)
// 此处主要以第二种方式进行实现
typedef Node StaticList[MAXSIZE];

void InitList(StaticList list);

int ListLength(const StaticList list);

/**
 * 查询链表的指定位置的结点
 *
 * return 如果未查询到则返回 -1，查询到则返回查询结点的前一个结点
 */
Position GetElemPrior(const StaticList list, Position pos);

void ListInsert(StaticList list, Position pos, ElemType elem);

void ListDelete(StaticList list, Position pos);

void show_list(StaticList list);

/**
 * 在静态链表头部进行插入
 */
void push_front(StaticList list, ElemType elem);
/**
 * 删除静态链表头部元素
 */
void pop_front(StaticList list);



// 辅助函数
/**
 * 分配空间
 */
Position Malloc_SL(StaticList list);
/**
 * 释放指定节点
 */
void Free_SL(StaticList list, Position p);


#endif	// __STATICLIST_H__
