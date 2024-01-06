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
int Tree[10001];
int Idx;

void PostOrder(int start, int end)
{
	if (start >= end)
		return;
	if (start == end - 1)
	{
		cout << Tree[start] << '\n';
		return;
	}
	int idx = start + 1;
	while(idx<end)
	{
		if (Tree[start] < Tree[idx])
			break;
		idx++;
	}
	PostOrder(start + 1, idx);
	PostOrder(idx, end);
	cout << Tree[start] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num;
	while (cin >> num)
		Tree[Idx++] = num;
	PostOrder(0, Idx);
	return 0;
}