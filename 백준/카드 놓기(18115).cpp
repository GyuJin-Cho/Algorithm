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
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	deque<int>dq;

	int card = 1;

	for(int i=n-1;i>=0;i--)
	{
		if (v[i] == 1)
			dq.push_back(card);
		else if(v[i]==2)
		{
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(tmp);
		}
		else if(v[i]==3)
		{
			dq.push_front(card);
		}
		card++;
	}

	for (int i = n - 1; i >= 0; i--)
		cout << dq[i] << ' ';

	return 0;
}