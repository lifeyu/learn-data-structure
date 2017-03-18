#ifndef __HEAP_STRING_H__
#define __HEAP_STRING_H__

/**
 * 串的堆分配存储表示
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef _Bool boolean;



typedef struct HeapString {		// 堆串的结构
	char * ch;			// 若是非空串，则按串长分配存储区，否则 ch 为 NULL
	int length;			// 串长度
	
} String;



/**
 * 给串赋值
 *
 * @param string
 * @param str
 * 		字符串
 */
void StrAssign(String *string, char *str);

/**
 * 复制串
 *
 * @param result
 * 			复制的结果
 * @param string
 * 			待复制的串
 */
void StrCopy(String *result, String *string);

/**
 * 串是否为空
 *
 * @param string
 *
 * @return boolean:true.是   false.否
 */
boolean StrEmpty(String *string);

/**
 * 串的比较
 *
 * @param string
 * @param compareString
 *
 * @return int:
 * 		大于0.第一个串大于第二个串
 * 		等于0.第一个串等于第二个串
 * 		小于0.第一个串小于第二个串
 */
int StrCompare(String *string, String *compareString);

/**
 * 串长度
 *
 * @param string
 */
int StrLength(String *string);

/**
 * 清空串
 *
 * @param string
 */
void ClearString(String *string);

/**
 * 拼接串
 *
 * @param result
 * 			拼接后的结果
 * @param s1
 *			待拼接的串
 * @param s2
 * 			待拼接的串
 */
void Concat(String *result, String *s1, String *s2);

/**
 * 截取串的子串
 *
 * @param result
 * 			截取后的结果
 * @param string
 * 			待截取的串
 * @param pos
 * 			截取的位置
 * @param len
 * 			截取的长度
 */
void SubString(String *result, String *string, int pos, int len);

/**
 * 判断串中是否存在制定的子串
 *
 * @param string
 * 			主串
 * @param indexString
 * 			子串
 * @param pos
 * 			查找起始位置
 *
 * @return 如果存在则返回子串第一次出现在主串中的位置，否则返回 -1
 */
int Index(String *string, String *indexString, int pos);

/**
 * 替换串中的字符
 * notes: 替换主串中出现所有与待替换串相等的不重叠的子串
 *
 * @param string
 * 			主串
 * @param repalceString
 * 			待替换串
 * @param exchange
 * 			替换串的字符
 */
void Replace(String *string, String *replaceString, String *exchange);

/**
 * 将指定串插入到主串中的指定位置
 *
 * @param string
 * 			主串
 * @param pos
 *			插入位置
 * @param insert
 * 			待插入串
 */
void StrInsert(String *string, int pos, String *insert);

/**
 * 删除串中指定的子串
 *
 * @param string
 * 			主串
 * @param pos
 *			删除位置
 * @param len
 * 			删除长度
 */
void StrDelete(String *string, int pos, int len);

/**
 * 销毁串
 *
 * @param string
 */
void DestroyString(String *string);



//------------------------------------------------------------------
// 辅助方法
//------------------------------------------------------------------

/**
 * 初始化串
 */
void initString(String *string);

/**
 * 显示串
 */
void show(String *string);

/**
 * 获取串实例 (创建并初始化)
 *
 * @param string
 * @param str
 * 			获取串实例字符串可为空.
 */
void getString(String *string, char *str);

#endif // __HEAP_STRING_H__
