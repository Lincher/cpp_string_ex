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

//字符串数字互转

//join

}
#endif