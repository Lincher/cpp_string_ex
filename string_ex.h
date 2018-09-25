#ifndef STRING_EX_H
#define STRING_EX_H
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
// using std::pair;

namespace string_ex{

	vector<string> split(const string &s, const string &seperator);

	inline string& Upper(string &str)
	{
		transform(str.begin(),str.end(),str.begin(),::toupper);
		return str;
	}
	inline string& Lower(string &str)
	{
		transform(str.begin(),str.end(),str.begin(),::tolower);
		return str;
	}

	inline void Remove(string &str,char c)
	{
		str.erase(std::remove(str.begin(), str.end(), c), str.end());
	}

	inline string& ltrim(string &str) {
		string::iterator p = find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isspace)));
		str.erase(str.begin(), p);
		return str;
	}

	inline string& rtrim(string &str) {
		string::reverse_iterator p = find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun(::isspace)));
		str.erase(p.base(), str.end());
		return str;
	}

	inline string& trim(string &str) {
		ltrim(rtrim(str));
		return str;
	}

	string& join(const vector<string> vecStr,const string seperator );

	size_t findc(string &str, char c, size_t appear_count);

	size_t finds(string &str, string s, size_t appear_count);

	string& snprintfex(char *format,size_t buff_size,...);
}

#endif