#ifndef __DULCYCLELIST_H__
#define __DULCYCLELIST_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;			// 双向循环链表存储值的类型
typedef _Bool boolean;

struct Node;				// 双向循环链表结点结构

typedef struct Node *PtrToNode;
typedef PtrToNode Position;		// 代表结点的位置

// 双向循环链表存储结构
typedef struct DulCycleList {		// 链表的结构：包括头结点，尾结点，链表长度
	Position first;			// 链表的头结点
	Position last;			// 链表的尾结点
	int size;
} DulCycleList;

void InitList(DulCycleList *list);

void DestroyList(DulCycleList *list);

void ClearList(DulCycleList *list);

/**
 * 如果双向循环链表为空，则返回 true；否则返回 false
 */
boolean ListEmpty(DulCycleList *list);

int ListLength(DulCycleList *list);

/**
 * 查询双向循环链表的指定位置的结点
 *
 * return 如果未查询到则返回 NULL，查询到则返回查询结点
 */
Position GetElem(DulCycleList *list, int pos);

/**
 * 查找双向循环链表的结点的值等于特定的值的前驱
 *
 * return 如果未查询到则返回 NULL，查询到则返回结点前驱
 */
Position PriorElem(DulCycleList *list, ElemType elem);

/**
 * 查找双向循环链表的结点的值等于特定的值的后继
 *
 * return 如果未查询到则返回 NULL，查询到则返回结点后继
 */
Position NextElem(DulCycleList *list, ElemType elem);

/**
 * 在双向循环链表的指定位置插入一个指定的值的结点
 */
void ListInsert(DulCycleList *list, int pos, ElemType elem);

/**
 * 删除双向循环链表的指定位置结点
 */
void ListDelete(DulCycleList *list, int pos);

void show_list(DulCycleList *list);

/**
 * 在双向循环链表头部进行插入
 */
void push_front(DulCycleList *list, ElemType elem);

/**
 * 在双向循环链表尾部进行插入
 */
void push_back(DulCycleList *list, ElemType elem);

/**
 * 删除双向循环链表头部元素
 */
void pop_front(DulCycleList *list);

/**
 * 删除双向循环链表尾部元素
 */
void pop_back(DulCycleList *list);

/**
 * 在双向循环链表中插入结点，并且结点的数据为指定的
 * 注意：目前此方法只支持，待插入的双向循环链表必须是按数据大小升序排列；如果不是，方法内部会自动进行排序后插入
 */
void insert_val(DulCycleList *list, ElemType elem);

/**
 * 删除双向循环链表的指定结点，目前只支持删除该指定值第一次出现的结点
 */
void delete_val(DulCycleList *list, ElemType elem);

/**
 * 查找指定值在双向循环链表中第一次出现时对应的结点
 *
 * return 如果未查找到则返回 NULL，查找到则返回结点
 */
Position find_val(DulCycleList *list, ElemType elem);

/**
 * 对双向循环链表按照结点值的升序排列
 */
void sort(DulCycleList *list);

/**
 * 对双向循环链表进行翻转
 */
void resver(DulCycleList *list);

struct Node {			// 双向循环链表的结点类型
	ElemType data;
	Position prior;
	Position next;
};


#endif	// __DULCYCLELIST_H__
