#include<iostream>
#include<queue>
#include<vector>
#include<set>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int T;
		cin >> T;
		multiset<int> q;
		for (int j = 0; j < T; j++)
		{
			char c;
			int num;
			cin >> c >> num;
			if (c == 'I')
			{
				q.insert(num);
			}
			else if (c == 'D')
			{
				if (!q.empty())
				{
					if (num == 1)
					{
						auto iter = q.end();
						iter--;
						q.erase(iter);
					}
					else
					{
						q.erase(q.begin());
					}
				}
			}
		}
		if (q.empty())
		{
			cout << "EMPTY"<<endl;
		}
		else
		{
			auto iter = q.end();
			iter--;
			cout << *iter << " " << *q.begin()<<endl;
		}
	}
	
	return 0;
}