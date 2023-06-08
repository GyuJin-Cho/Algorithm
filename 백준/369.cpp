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

using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	int ans = 0;
	for(int i=1;i<=N;i++)
	{
		s = to_string(i);
		for(int i=0;i<s.size();i++)
		{
			if (s[i] == '3'||s[i] == '6'||s[i] == '9')
				ans++;
		}
	}
	cout << ans;
	return 0;
}