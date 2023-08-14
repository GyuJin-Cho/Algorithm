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
int s[20][20];
int n;
int DFS(int index, vector<int>& first, vector<int>& second)
{
	if (index == n)
	{
		if (first.size() == 0)
			return -1;
		if (second.size() == 0 )
			return -1;
		int t1 = 0;
		int t2 = 0;
		for (int i = 0; i < first.size(); i++)
		{
			for (int j = 0; j < first.size(); j++)
			{
				if (i == j)
					continue;
				t1 += s[first[i]][first[j]];
			}
		}
		for (int i = 0; i < second.size(); i++)
		{
			for (int j = 0; j < second.size(); j++)
			{
				if (i == j)
					continue;
				t2 += s[second[i]][second[j]];
			}
		}
		int diff = t1 - t2;
		if (diff < 0)
			diff = -diff;
		return diff;
	}
	int answer = -1;
	first.push_back(index);
	int t1 = DFS(index + 1, first, second);
	if (answer == -1 || (t1 != -1 && answer > t1))
	{
		answer = t1;
	}
	first.pop_back();
	second.push_back(index);
	int t2 = DFS(index + 1, first, second);
	if (answer == -1 || (t2 != -1 && answer > t2))
	{
		answer = t2;
	}
	second.pop_back();
	return answer;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			cin >> s[i][j];
		}
	}
	vector<int>first, second;
	cout << DFS(0, first, second);
	return 0;
}