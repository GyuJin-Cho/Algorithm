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
int n;
char a[20];
vector<string> answer;
bool check[10];

bool ok(string num)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '<')
		{
			if (num[i] > num[i + 1])
				return false;
		}
		else if (a[i] == '>')
		{
			if (num[i] < num[i+1] + 1)
				return false;
		}
	}
	return true;
}

void DFS(int index, string num)
{
	if (index == n + 1)
	{
		if (ok(num))
		{
			answer.push_back(num);
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (check[i])
			continue;
		check[i] = true;
		DFS(index + 1, num + to_string(i));
		check[i] = false;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	DFS(0, "");
	sort(answer.begin(), answer.end(),greater<>());
	cout << answer[0] << '\n';
	cout << answer[answer.size() - 1];
	return 0;
}