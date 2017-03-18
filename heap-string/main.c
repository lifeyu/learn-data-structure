#include "heapstring.h"

void main()
{
	String string;
	getString(&string, NULL);

	int select = 1;
	char str[20];
	char str1[20];
	char str2[20];
	boolean flag;
	int flagInt;
	int pos;
	int len;
	while (select)
	{
		printf("*********************************************\n");	
		printf("*  [1]  assign           [2]  copy          *\n");	
		printf("*  [3]  empty            [4]  compare       *\n");	
		printf("*  [5]  length           [6]  clear         *\n");	
		printf("*  [7]  concat           [8]  substring     *\n");	
		printf("*  [9]  index            [10] replace       *\n");	
		printf("*  [11] insert           [12] delete        *\n");	
		printf("*  [13] show                                *\n");	
		printf("*  [0]  quit                                *\n");	
		printf("*********************************************\n");	

		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			printf("请输入赋值的字符串.\n");
			scanf("%s", str);
			StrAssign(&string, str);
			break;	
		case 2:
			printf("请输入需要复制的字符串.\n");
			scanf("%s", str);
			String copyResult;
			getString(&copyResult, NULL);
			String tmp;
			getString(&tmp, str);
			StrCopy(&copyResult, &tmp);
			show(&copyResult);
			break;
		case 3:
			flag = StrEmpty(&string);
			if (flag) printf("串为空.\n");
			break;
		case 4:
			printf("请输入比较的字符串.\n");
			scanf("%s", str);
			String compare;
			getString(&compare, str);
			flagInt = StrCompare(&string, &compare);
			if (flagInt > 0)
			{
				printf("字符串大于比较的字符串.\n");	
			}
			else if (flagInt < 0)
			{
				printf("字符串小于比较的字符串.\n");	
			}
			else
			{
				printf("字符串等于比较的字符串.\n");	
			}
			break;
		case 5:
			printf("串的长度为 %d.\n", StrLength(&string));
			break;
		case 6:
			ClearString(&string);
			break;
		case 7:
			printf("请输入拼接的字符串 1.\n");
			scanf("%s", str1);
			printf("请输入拼接的字符串 2.\n");
			scanf("%s", str2);
			String concatResult;
			getString(&concatResult, NULL);
			String s1;
			getString(&s1, str1);
			String s2;
			getString(&s2, str2);
			Concat(&concatResult, &s1, &s2);
			show(&concatResult);
			break;
		case 8:
			printf("请输入截取的位置.\n");
			scanf("%d", &pos);
			printf("请输入截取的长度.\n");
			scanf("%d", &len);
			String subResult;
			getString(&subResult, NULL);
			SubString(&subResult, &string, pos, len);
			show(&subResult);
			break;
		case 9:
			printf("请输入查找的字符串.\n");
			scanf("%s", str);
			printf("请输入查找的起始位置.\n");
			scanf("%d", &pos);
			String indexString;
			getString(&indexString, str);
			int find = Index(&string, &indexString, pos);
			if (find != -1)
			{
				printf("查找字符串在主串的位置为 %d.\n", find);	
			}
			else
			{
				printf("对不起，主串中不存在要查找的字符串.\n");	
			}
			break;
		case 10:
			printf("请输入需要替换的字符串.\n");
			scanf("%s", str1);
			printf("请输入替换后的字符串.\n");
			scanf("%s", str2);
			String replaceString;
			getString(&replaceString, str1);
			String exchange;
			getString(&exchange, str2);
			Replace(&string, &replaceString, &exchange);
			break;
		case 11:
			printf("请输入插入的字符串.\n");
			scanf("%s", str);
			printf("请输入插入的位置.\n");
			scanf("%d", &pos);
			String insert;
			getString(&insert, str);
			StrInsert(&string, pos, &insert);
			break;
		case 12:
			printf("请输入删除的位置.\n");
			scanf("%d", &pos);
			printf("请输入删除的长度.\n");
			scanf("%d", &len);
			StrDelete(&string, pos, len);
			break;
		case 13:
			show(&string);
			break;
		default:
			printf("输入的选择错误，请重新输入!\n");
			break;
		}
	}
}
