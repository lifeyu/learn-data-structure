#include "seqstring.h"

void StrAssign(String string, char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		string[i] = str[i];	
	}
	string[len] = END_IDENTITY;
}

void StrCopy(String result, String string)
{
	int len = StrLength(string);
	for (int i = 0; i < len; i++)
	{
		result[i] = string[i];	
	}	
	result[len] = END_IDENTITY;
}

boolean StrEmpty(String string)
{
	return string[0] == END_IDENTITY;
}

int StrCompare(String string, String compareString)
{
	int result = 0;
	while (*string != END_IDENTITY || *compareString != END_IDENTITY)
	{
		result = *string - *compareString;
		if (result != 0) break;	

		string++;
		compareString++;
	}

	if (result > 0)
	{
		result = 1;	
	}
	else if(result < 0)
	{
		result = -1;	
	}

	return result;
}

int StrLength(String string)
{
	int len = 0;
	while (*string != END_IDENTITY)
	{
		len++;
		string++;	
	}

	return len;
}

void ClearString(String string)
{
	string[0] = END_IDENTITY;
}

void Concat(String result, String s1, String s2)
{
	int s1_len = StrLength(s1);
	int s2_len = StrLength(s2);

	if (s1_len + s2_len <= MAXSTRSIZE)
	{
		int i;
		for (i = 0; i < s1_len; i++)
		{
			result[i] = s1[i];
		}	
		for (int j = 0; j < s2_len; j++)
		{
			result[i + j] = s2[j];	
		}
		result[s1_len + s2_len] = END_IDENTITY;
	}
	else if (s1_len < MAXSTRSIZE)
	{
		int i;
		for (i = 0; i < s1_len; i++)
		{
			result[i] = s1[i];
		}	
		for (int j = 0; j < MAXSTRSIZE - s1_len; j++)
		{
			result[i + j] = s2[j];	
		}
		result[MAXSTRSIZE] = END_IDENTITY;
	}
	else
	{
		for (int i = 0; i < s1_len; i++)
		{
			result[i] = s1[i];
		}	
		result[MAXSTRSIZE] = END_IDENTITY;
	}
}

void SubString(String result, String string, int pos, int len)
{
	int str_len = StrLength(string);
	if (pos < 0 || pos > str_len || len < 0 || len > str_len - pos)
	{
		printf("截取失败，不符合截取条件.\n");	
		return;
	}

	int j = pos;
	for (int i = 0; i < len; i++)
	{
		result[i] = string[j + i];	
	}
	result[len] = END_IDENTITY;
}

int Index(String string, String indexString, int pos)
{
	int s_len = StrLength(string);
	if (pos > s_len)
	{
		//printf("位置不符合条件，查找失败.\n");	
		return -1;
	}

	int i = pos;
	int j = 0;
	while (string[i] != END_IDENTITY && indexString[j] != END_IDENTITY)
	{
		if (string[i] == indexString[j])
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

	if (indexString[j] == END_IDENTITY) return i - j;

	return -1;
}

void Replace(String string, String replaceString, String exchange)
{
	int s_len = StrLength(string);
	int r_len = StrLength(replaceString);
	int e_len = StrLength(exchange);	


	int index = -1;
	int pos = 0;

	while (pos < s_len)
	{
		index = Index(string, replaceString, pos);
		if (index == -1) return;

		StrDelete(string, index, r_len);
		StrInsert(string, index, exchange);		

		pos = index + e_len;
	}
}

void StrInsert(String string, int pos, String insert)
{
	if (pos < 0)
	{
		printf("插入失败，不符合插入条件.\n");	
		return;
	}

	int s_len = StrLength(string);
	int i_len = StrLength(insert);
	
	if (s_len + i_len > MAXSTRSIZE)
	{
		i_len = MAXSTRSIZE - s_len;	
	}	

	for (int i = s_len - 1; i >= pos; i--)
	{
		string[i + i_len] = string[i];	
	}

	int j = pos;
	for (int i = 0; i < i_len; i++)
	{
		string[j + i] = insert[i];	
	}
	string[s_len + i_len] = END_IDENTITY;
}

void StrDelete(String string, int pos, int len)
{
	int s_len = StrLength(string);
	if (pos < 0 || pos > s_len || len <= 0 || len > s_len - pos)
	{
		printf("删除失败，不符合删除条件.\n");	
		return;
	}

	for (int i = pos; i < s_len; i++)
	{
		string[i] = string[i + len];	
	}	
	string[s_len - len] = END_IDENTITY;
}



//------------------------------------------------------------------
// 辅助方法
//------------------------------------------------------------------
//
void initString(String string)
{
	string[0] = END_IDENTITY;
}

void show(String string)
{
	printf("%s\n", string);
}

void getString(String string, char *str)
{
	initString(string);
	if (str != NULL) StrAssign(string, str);
}
