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
bool breakingchanal[10];

bool check(int i)
{
	string s = to_string(i);
	for(int i=0;i<s.size();i++)
	{
		if (breakingchanal[s[i] - 48])
		{
			return false;
		}
	}
	return true;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int chanal;
	cin >> chanal;
	int m,Breaking;
	cin >> m;

	for(int i=0;i<m;i++)
	{
		cin >> Breaking;
		breakingchanal[Breaking] = true;
	}

	int Min = abs(chanal - 100);
	for(int i=0;i <= 1000000;i++)
	{
		if(check(i))
		{
			int tmp = abs(chanal - i) + to_string(i).size();
			Min = min(tmp, Min);
		}
	}
	cout << Min;
	
	return 0;
}