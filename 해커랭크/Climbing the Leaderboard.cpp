#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	stack<int> scores;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (scores.empty() || scores.top() != a)
		{
			scores.push(a);
		}
	}
	cin >> m;
	vector<int> player;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		player.push_back(a);
	}

	for (int i = 0; i < player.size(); i++)
	{
		while (!scores.empty() && player[i] >= scores.top())
		{
			scores.pop();
		}
		cout << scores.size()+1 << endl;
	}
	return 0;
}