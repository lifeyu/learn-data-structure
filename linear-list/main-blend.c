#include "seqlist.h"

/**
 * 测试其他顺序表复杂的操作
 */
void main()
{
	List la, lb, lc;

	// init la and insert data
	InitList(&la);
	push_back(&la, 1);
	push_back(&la, 3);
	push_back(&la, 5);
	push_back(&la, 7);
	push_back(&la, 9);

	// init lb and insert data
	InitList(&lb);
	push_back(&lb, 2);
	push_back(&lb, 4);
	push_back(&lb, 6);
	push_back(&lb, 8);
	push_back(&lb, 10);
	
	MergeList(&la, &lb, &lc);
	show_list(&lc);
}
