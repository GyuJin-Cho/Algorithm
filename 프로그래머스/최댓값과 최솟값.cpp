#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(string s)
{
	string answer = "";

	string tmp;
	vector<int> v;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		{
			v.push_back(atoi(tmp.c_str()));
			tmp = "";
		}
		else
		{
			tmp += s[i];
		}
	}
	v.push_back(atoi(tmp.c_str()));
	sort(v.begin(), v.end());
	answer = to_string(v[0])+" "+to_string(v[v.size() - 1]);
	return answer;
}
int main()
{
	string s = "1 2 3 4";
	cout << solution(s);
	return 0;
}