#ifndef __DULLINKLIST_H__
#define __DULLINKLIST_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;			// 双向链表存储值的类型
typedef _Bool boolean;

struct Node;				// 双向链表结点结构

typedef struct Node *PtrToNode;
typedef PtrToNode Position;		// 代表结点的位置

// 双向链表存储结构
typedef struct DulLinkList {		// 链表的结构：包括头结点，尾结点，链表长度
	Position first;			// 链表的头结点
	Position last;			// 链表的尾结点
	int size;
} DulLinkList;

void InitList(DulLinkList *list);

void DestroyList(DulLinkList *list);

void ClearList(DulLinkList *list);

/**
 * 如果双向链表为 NULL，则返回 true；否则返回 false
 */
boolean ListEmpty(DulLinkList *list);

int ListLength(DulLinkList *list);

/**
 * 查询双向链表的指定位置的结点
 *
 * return 如果未查询到则返回 NULL, 查询到则返回查询结点
 */
Position GetElem(DulLinkList *list, int pos);

/**
 * 查询双向链表的结点的值等于特定的值的前驱
 *
 * return 如果未查询到则返回 NULL，查询到则返回结点前驱
 */
Position PriorElem(DulLinkList *list, ElemType elem);

/**
 * 查找双向链表的结点的值等于特定的值的后继
 *
 * return 如果未查询到则返回 NULL，查询到则返回结点后继
 */
Position NextElem(DulLinkList *list, ElemType elem);

/**
 * 在双向链表的指定位置插入一个指定值的结点
 */
void ListInsert(DulLinkList *list, int pos, ElemType elem);

/**
 * 删除双向链表的指定位置结点
 */
void ListDelete(DulLinkList *list, int pos);

void show_list(DulLinkList *list);

/**
 * 在双向链表头部进行插入
 */
void push_front(DulLinkList *list, ElemType elem);

/**
 * 在双向链表尾部进行插入
 */
void push_back(DulLinkList *list, ElemType elem);

/**
 * 删除双向链表头部元素
 */
void pop_front(DulLinkList *list);

/**
 * 删除双向链表尾部元素
 */
void pop_back(DulLinkList *list);

/**
 * 在双向链表中插入指定结点，并且结点的数据为指定的
 * 注意：目前此方法只支持，待插入的双向链表必须是按数据大小升序排列；如果不是，方法内部会自动进行排序后插入
 */
void insert_val(DulLinkList *list, ElemType elem);

/**
 * 删除双向链表的指定结点，目前只能支持删除该指定值第一次出现的结点
 */
void delete_val(DulLinkList *list, ElemType elem);

/**
 * 查找指定值在双向链表中第一次出现时对应的结点
 *
 * return 如果未查找到则返回 NULL，查找到则返回结点
 */
Position find_val(DulLinkList *list, ElemType elem);

/**
 * 对双向链表按照结点值的升序排列
 */
void sort(DulLinkList *list);

/**
 * 对双向链表进行翻转
 */
void resver(DulLinkList *list);

struct Node {				// 双向链表的结点类型
	ElemType data;
	Position prior;
	Position next;
};


#endif	// __DULLINKLIST_H__
