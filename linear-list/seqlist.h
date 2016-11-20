#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define LIST_INIT_SIZE 8     // 线性表存储空间的初始分配量
#define LISTINCREMENT  10      // 线性表存储空间的分配增量

typedef int ElemType;          // 线性表存储值的类型

typedef struct {
  ElemType *elem;          // 存储空间基址
  int     length;          // 当前长度 (即当前线性表实际已用的长度)
  int   listsize;          // 当前分配的存储容量 (以 sizeof (ElemType) 为单位)
} List;

typedef _Bool boolean;      // 重定义 bool 类型

void InitList(List *list);

void DestroyList(List *list);

/**
 * 将顺序表重置为空表
 */
void ClearList(List *list);

boolean ListEmpty(List *list);

int ListLength(List *list);

/**
 * 查找指定位置的元素
 *
 * @return true.查找成功   false.查找失败
 */
boolean GetElem(List *list, int pos, ElemType *elem);

boolean PriorElem(List *list, ElemType curElem, ElemType *preElem);

boolean NextElem(List *list, ElemType curElem, ElemType *nextElem);

void ListInsert(List *list, int pos, ElemType elem);

boolean ListDelete(List *list, int pos, ElemType *elem);

void show_list(List *list);

/**
 * 从顺序表头部插入数据
 */
void push_front(List *list, ElemType elem);

/**
 * 从顺序表尾部插入数据
 */
void push_back(List *list, ElemType elem);

/**
 * 从顺序表头部删除一个元素
 */
void pop_front(List *list);

/**
 * 从顺序表尾部删除一个元素
 */
void pop_back(List *list);

/**
 * 删除顺序表中指定值首次出现时对于的元素
 */
void delete_val(List *list, ElemType elem);

/**
 * 查找指定值在顺序表中首次出现的位置
 *
 * @return -1.查找失败 
 */
int find(List *list, ElemType elem);

void sort(List *list);

/**
 * 对顺序表进行翻转
 */
void resver(List *list);

/**
 * 已知顺序线性表 la 和 lb 的元素按值非递减排列
 * 归并 la 和 lb 得到新的顺序表 lc, lc 的元素也按值非递减排列
 */
void MergeList(List *la, List *lb, List *lc);

/**
 * 如果 List 默认创建空间已满, 则再次为 List 分配空间
 */
boolean AddCapacity(List *list);

#endif	// SEQLIST_H__
