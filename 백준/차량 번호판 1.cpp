#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>

using namespace std;
int go(string &s, int index, char last)
{
	if (s.length() == index)
		return 1;
	char start = (s[index] == 'c' ? 'a' : '0');
	char end(s[index] == 'c' ? 'z' : '9');
	int answer = 0;
	for(char i=start;i<=end;i++)
	{
		if(i!=last)
		{
			answer += go(s, index + 1, i);
		}
	}
	return answer;
}
int main()
{
	string s;
	cin >> s;
	cout << go(s, 0, ' ');

	return 0;
}