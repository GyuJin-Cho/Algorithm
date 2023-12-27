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

int main()
{
	string s,target,tmp;
	cin >> s;
	cin >> target;
	for(int i=0;i<s.length();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			continue;
		tmp += s[i];
	}
	if (tmp.find(target)!=string::npos)
		cout << 1;
	else
		cout << 0;
	return 0;
}