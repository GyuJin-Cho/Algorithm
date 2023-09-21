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
int s[10];
int w[10];
int n;
int DFS(int idx)
{
	if (idx == n)
	{
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			if (s[i] <= 0)
				cnt++;
		}
		return cnt;
	}
	if(s[idx]<=0)
	{
		return DFS(idx + 1);
	}
	int answer = 0;
	bool ch = false;
	for(int j=0;j<n;j++)
	{
		int i = idx;
		if(i==j)
			continue;
		if(s[j]>0)
		{
			ch = true;
			s[i] -= w[j];
			s[j] -= w[i];
			int tmp = DFS(idx + 1);
			if (answer < tmp)
				answer = tmp;
			s[i] += w[j];
			s[j] += w[i];
		}
	}
	if (!ch)
		return DFS(idx+1);
	return answer;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];

	cout << DFS(0);

	return 0;
}