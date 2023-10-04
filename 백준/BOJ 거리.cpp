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

char GetPrev(char x)
{
	if (x == 'B')
		return 'J';
	else if (x == 'O')
		return 'B';
	else if (x == 'J')
		return 'O';
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> d(n, - 1);
	d[0] = 0;
	for(int i=1;i<n;i++)
	{
		char now = s[i];
		char prev = GetPrev(now);
		for(int j=0;j<i;j++)
		{
			if(d[j]==-1)
				continue;
			if(s[j]!=prev)
				continue;
			int cost = d[j] + pow(i - j, 2);
			if (d[i] == -1 || d[i] > cost)
				d[i] = cost;
		}
	}
	cout << d[n - 1];
	return 0;
}