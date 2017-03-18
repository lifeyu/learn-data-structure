#include "heapstring.h"

void StrAssign(String *string, char *str)
{
	if (string -> ch != NULL) free(string -> ch);

	int len = strlen(str);
	string -> ch = (char *) malloc(sizeof(char) * len);		
	assert(string -> ch != NULL);

	for (int i = 0; i < len; i++)
	{
		string -> ch[i] = str[i];	
	}
	string -> length = len;
}

void StrCopy(String *result, String *string)
{
	if (result -> ch != NULL) free(string -> ch);

	int len = StrLength(string);	
	result -> ch = (char *) malloc(sizeof(char) * len);
	assert(result -> ch != NULL);

	for (int i = 0; i < len; i++)
	{
		result[i] = string[i];	
	}
	result -> length = len;
}

boolean StrEmpty(String *string)
{
	return string -> length == 0;
}

int StrCompare(String *string, String *compareString)
{
	if (string -> length == 0 && compareString -> length == 0) return 0;

	int result = 0;

	int i = 0;
	int j = 0;
	while (i < string -> length && j < compareString -> length)
	{
		if (string -> ch[i] > compareString -> ch[j])
		{
			return 1;	
		}
		else if (string -> ch[i] < compareString -> ch[j])
		{
			return -1;	
		}
		else
		{
			i++;
			j++;	
		}	
	}

	if (i < string -> length) result = 1;
	if (j < compareString -> length) result = -1;

	return result;
}

int StrLength(String *string)
{
	return string -> length;
}

void ClearString(String *string)
{
	string -> length = 0;
	if (string -> ch != NULL) free(string -> ch);
	string -> ch = NULL;
}

void Concat(String *result, String *s1, String *s2)
{
	if (result -> ch != NULL) free(result -> ch);

	int s1_len = StrLength(s1);
	int s2_len = StrLength(s2);

	result -> ch = (char *) malloc(sizeof(char) * (s1_len + s2_len));
	assert(result -> ch != NULL);

	int i;
	for (i = 0; i < s1_len; i++)
	{
		result -> ch[i] = s1 -> ch[i];	
	}
	for (int j = 0; j < s2_len; j++)
	{
		result -> ch[i + j] = s2 -> ch[j];	
	}
	result -> length = s1_len + s2_len;
}

void SubString(String *result, String *string, int pos, int len)
{
	int str_len = StrLength(string);
	if (pos < 0 || pos > str_len || len < 0 || len > str_len - pos)
	{
		printf("截取失败，不符合截取条件.\n");
		return;	
	}

	if (result -> ch != NULL) free(result -> ch);
	result -> ch = (char *) malloc(sizeof(char) * len);
	assert(result -> ch != NULL);

	int j = pos;
	for (int i = 0; i < len; i++)
	{
		result -> ch[i] = string -> ch[i + j];	
	}
	result -> length = len;
}

int Index(String *string, String *indexString, int pos)
{
	if (pos > string -> length) return -1;

	int i = pos;
	int j = 0;
	while (i < string -> length && j < indexString -> length)
	{
		if (string -> ch[i] == indexString -> ch[j])
		{
			i++;
			j++;	
		}
		else
		{
			i = i - j + 1;	
			j = 0;
		}	
	}

	if (j == indexString -> length) return i - j;

	return -1;
}

void Replace(String *string, String *replaceString, String *exchange)
{
	int index = -1;
	int pos = 0;

	while (pos < string -> length)
	{
		index = Index(string, replaceString, pos);
		if (index == -1) return;

		StrDelete(string, index, replaceString -> length);
		StrInsert(string, index, exchange);	

		pos = index + exchange -> length;
	}
}

void StrInsert(String *string, int pos, String *insert)
{
	if (insert -> length == 0) return;
	if (pos < 0 || pos > string -> length) return;

	char *tmp = (char *) realloc(string -> ch, sizeof(char) * (string -> length + insert -> length));
	assert(tmp != NULL);
	string -> ch = tmp;

	for (int i = string -> length; i >= pos; i--)
	{
		string -> ch[i + insert -> length] = string -> ch[i];	
	}

	int j = pos;
	for (int i = 0; i < insert -> length; i++)
	{
		string -> ch[i + j] = insert -> ch [i];	
	}
	string -> length += insert -> length;
}

void StrDelete(String *string, int pos, int len)
{
	int s_len = StrLength(string);
	if (pos < 0 || pos > s_len || len <= 0 || len > s_len - pos)
	{
		printf("删除失败，不符合删除条件.\n");	
		return;
	}

	for (int i = pos; i < s_len; i++)
	{
		string -> ch[i] = string -> ch[i + len];	
	}
	string -> length -= len;
}



//------------------------------------------------------------------
// 辅助方法
//------------------------------------------------------------------

void initString(String *string)
{
	string -> ch = NULL;
	string -> length = 0;
}

void show(String *string)
{
	for (int i = 0; i < string -> length; i++)
	{
		printf("%c", string -> ch[i]);	
	}
	printf("\n");
}

void getString(String *string, char *str)
{
	initString(string);
	if (str != NULL) StrAssign(string, str);
}
