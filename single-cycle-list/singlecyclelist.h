#ifndef __SINGLECYCLELIST_H__
#define __SINGLECYCLELIST_H__


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;		// 单循环链表存储值的类型
typedef _Bool boolean;

struct Node;			// 单循环链表结点结构

typedef struct Node *PtrToNode;
typedef PtrToNode Position;	// 结点的位置

// 单链表存储结构
// 链表的结构：包括头结点，尾结点，链表长度
typedef struct SingleCycleList {
	Position first;
	Position last;
	int size;
} SingleCycleList;

void InitList(SingleCycleList *list);

void DestoryList(SingleCycleList *list);

void ClearList(SingleCycleList *list);

/**
 * 如果单循环链表为 NULL，则返回 true；否则返回 false
 */
boolean ListEmpty(SingleCycleList *list);

int ListLength(SingleCycleList *list);

/**
 * 查询单循环链表中指定位置的结点
 *
 * return 如果未查询到则返回 NULL，查询到则返回查询结点
 */
Position GetElem(SingleCycleList *list, int pos);

/**
 * 查询单循环链表中指定位置的前驱结点
 *
 * return 如果未查询到则返回 NULL，查询到则返回查询结点
 */
Position GetElemPrior(SingleCycleList *list, int pos);

/**
 * 查询单循环链表的结点的值等于特定值的前驱
 * // TODO: 此处不做循环的查找
 * 
 * return 如果未查询到则返回 NULL，查询到则返回结点前驱
 */
Position PriorElem(SingleCycleList *list, ElemType elem);

/**
 * 查询单循环链表的结点的值等于特定值的后继
 * // TODO: 此处不做循环的查找
 *
 * return 如果未查询到则返回 NULL，查询到则返回结点后继
 */
Position NextElem(SingleCycleList *list, ElemType elem);

/**
 * 在单循环链表的指定位置插入一个指定值的结点
 */
void ListInsert(SingleCycleList *list, int pos, ElemType elem);

/**
 * 删除单循环链表的指定位置的结点
 */
void ListDelete(SingleCycleList *list, int pos);

void show_list(SingleCycleList *list);

/**
 * 头部进行插入
 */
void push_front(SingleCycleList *list, ElemType elem);

/**
 * 尾部进行插入
 */
void push_back(SingleCycleList *list, ElemType elem);

/**
 * 删除头部元素
 */
void pop_front(SingleCycleList *list);

/**
 * 删除尾部元素
 */
void pop_back(SingleCycleList *list);

/**
 * 在单循环链表中插入指定结点，并且结点的数据为指定的
 * 注意：目前此方法只支持，待插入的单循环链表必须是按数据大小升序排列；如果不是，方法内部会自动进行排序后再插入
 */
void insert_val(SingleCycleList *list, ElemType elem);

/**
 * 删除单循环链表的指定结点，目前只能支持删除该指定值第一次出现的结点
 */
void delete_val(SingleCycleList *list, ElemType elem);

/**
 * 查找指定值在单循环链表中第一次出现时对应的结点
 *
 * return 如果未查找到则返回 NULL，查找到则返回结点
 */
Position find_val(SingleCycleList *list, ElemType elem);

/**
 * 对单循环链表进行排序
 */
void sort(SingleCycleList *list);

/**
 * 对单循环链表进行翻转
 */
void resver(SingleCycleList *list);

// 单循环链表结点类型
struct Node {
	ElemType data;
	Position next;
};


#endif	// __SINGLECYCLELIST_H__
