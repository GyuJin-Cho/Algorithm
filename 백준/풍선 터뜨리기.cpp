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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	deque<pair<int,int>> dq;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		dq.push_back(make_pair(num, i + 1));
	}

	while(!dq.empty())
	{
		int cur = dq.front().first;
		cout << dq.front().second<<' ';
		dq.pop_front();
		if (dq.empty())
			break;

		if(cur>0)
		{
			for(int i=0;i<cur-1;i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for(int i=0;i<(-1)*cur;i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}