#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;			// 单链表存储值的类型
typedef _Bool boolean;

struct Node;				// 单链表节点结构

typedef struct Node *PtrToNode;
typedef PtrToNode Position;		// 代表节点的位置

// 单链表存储结构
typedef struct LinkList {		// 链表的结构:包括头结点，尾节点，链表长度
	Position first;			// 链表的头节点
	Position last;			// 最后一个节点
	int size;
} LinkList;

void InitList(LinkList *list);

void DestroyList(LinkList *list);

void ClearList(LinkList *list);

/**
 * 如果单链表为 NULL, 则返回 true; 否则返回 false
 */
boolean ListEmpty(LinkList *list);

int ListLength(LinkList *list);

// TODO 按位置查询对链表作用不大!
/**
 * 查询单链表的指定位置的节点
 *
 * return 如果未查询到则返回 NULL, 查询到则返回查询节点
 */
Position GetElem(LinkList *list, int pos);

/**
 * 查询单链表的指定位置的节点
 *
 * return 如果未查询到则返回 NULL, 查询到则返回查询节点的前一个节点
 */
Position GetElemPrior(LinkList *list, int pos);

/**
 * 查询单链表的节点的值等于特定的值的前驱
 *
 * return 如果未查询到则返回 NULL, 查询到则返回节点前驱
 */
Position PriorElem(LinkList *list, ElemType elem);

/**
 * 查询单链表的节点的值等于特定的值的后继
 *
 * return 如果未查询到则返回 NULL， 查询到则返回节点后继
 */
Position NextElem(LinkList *list, ElemType elem);

// TODO 按位置插入对链表作用不大!
/**
 * 在单链表的指定位置插入一个指定值的节点
 */
void ListInsert(LinkList *list, int pos, ElemType elem);

/**
 * 删除单链表的指定位置的节点
 */
void ListDelete(LinkList *list, int pos);

void show_list(LinkList *list);

/**
 * 在单链表头部进行插入
 */
void push_front(LinkList *list, ElemType elem);
/**
 * 在单链表尾部进行插入
 */
void push_back(LinkList *list, ElemType elem);
/**
 * 删除单链表头部元素
 */
void pop_front(LinkList *list);
/**
 * 删除单链表尾部元素
 */
void pop_back(LinkList *list);

/**
 * 在单链表中插入指定节点, 并且节点的数据为指定的；
 * 注意：目前此方法只支持, 待插入的单链表必须是按数据大小升序排列;如果不是, 方法内部会自动进行排序后再插入
 */
void insert_val(LinkList *list, ElemType elem);

/**
 * 删除单链表的指定值节点, 目前只能支持删除该指定值第一次出现的节点 
 */
void delete_val(LinkList *list, ElemType elem);

/**
 * 查找指定值在单链表中第一次出现时对应的节点
 * return 如果为查找到则返回 NULL, 查找到则返回节点 
 */
Position find_val(LinkList *list, ElemType elem);

/**
 * 对单链表按照节点值升序排列
 */
void sort(LinkList *list);

/**
 * 对单链表进行翻转
 */
void resver(LinkList *list);

struct Node {		// 单链表节点类型
	ElemType data;
	Position next;
};

#endif  // __LINKLIST_H__
