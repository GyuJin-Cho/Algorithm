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

int N;

int arr[101];
int exist[101];
int visit[101];


bool DFS(int start, int from, int to)
{

	if (start == to)
		return true;

	if (visit[to] == 1)
		return false;

	visit[to] = 1;
	return DFS(start, to, arr[to]);

}

int main()
{

	cin >> N;


	for (int i = 1; i <= N; i++) 
	{
		cin >> arr[i];
		exist[arr[i]] = 1;
	}

	vector<int> answer;

	for (int i = 1; i <= N; i++)
	{
		if (exist[i] == 1)
		{
			for (int j = 1; j <= N; j++)
				visit[j] = 0;

			if (DFS(i, i, arr[i]))
				answer.push_back(i);
		}
	}
	cout << answer.size() << '\n';

	for (int item : answer)
		cout << item << '\n';

	return 0;

}