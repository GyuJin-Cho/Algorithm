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
	deque<int>DQ;
	int n, m;
	int left, right;
	int cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		DQ.push_back(i);
	}

	while (m--)
	{
		int num;
		cin >> num;

		for (int i = 0; i < DQ.size(); i++)
		{
			if (DQ[i] == num)
			{
				left = i;
				right = DQ.size() - i;
				break;
			}
		}

		if (left <= right)
		{
			while (1)
			{
				if (DQ.front() == num)
					break;
				DQ.push_back(DQ.front());
				DQ.pop_front();
				cnt++;
			}
			DQ.pop_front();
		}
		else
		{
			cnt++;
			while (1)
			{
				if (DQ.back() == num)
					break;
				DQ.push_front(DQ.back());
				DQ.pop_back();
				cnt++;
			}
			DQ.pop_back();
		}
	}
	cout << cnt;
	return 0;
}