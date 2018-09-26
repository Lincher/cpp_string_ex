#include "xstring.h"
#include <algorithm>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#if _MSC_VER
#define snprintf _snprintf
#endif

vector<string> xstring::split(const string &s, const string &seperator)
{
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0)
		{
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x])
				{
					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0)
		{
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x])
				{
					flag = 1;
					break;
				}
				if (flag == 0)
					++j;
		}
		if (i != j)
		{
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}


string& xstring::join(const vector<string> vecStr,const string seperator )
{
	size_t vec_size = vecStr.size();
	string join_str;
	for(size_t i=0;i<vec_size-1;i++)
	{
		join_str+=vecStr[i];
		join_str+=seperator;
	}
	return join_str+vecStr[vec_size-1];
}

size_t xstring::findc(string &str, char c, size_t appear_count)
{
	if(appear_count==0)
		return string::npos;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == c)
		{
			appear_count--;
			if(appear_count==0)
			{
				return i;
			}
		}
	}
	return string::npos;
}
size_t xstring::finds(string &str, string s, size_t appear_count)
{
	if(appear_count==0)
		return string::npos;
	size_t pos=0;
	while(appear_count>0){
		pos = str.find(s);
		if(pos!=string::npos)
		{
			appear_count--;
		}
	}
	return pos;
}

string &xstring::snprintfex(char *format,size_t buff_size,...)
{
	assert(buff_size>0);
	va_list va;
	char *p_data=new char[buff_size+1];
	if(p_data==NULL)
		return string("");
	va_start(va,buff_size);
	snprintf(p_data,buff_size, format,va);
	va_end(va);
	string out_str(p_data);
	delete p_data;
	return out_str;
}
