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
int k;
int input[10024];
vector<int> arr[10];
void insertTree(int depth, int start, int end)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	arr[depth].push_back(input[mid]);
	insertTree(depth + 1, start, mid);
	insertTree(depth + 1, mid + 1, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;

	int num;
	int idx = 0;
	while (cin >> num)
		input[idx++] = num;
	insertTree(0, 0, idx);

	for(int i=0;i<k;i++)
	{
		for(auto v : arr[i])
		{
			cout << v << ' ';
		}
		cout << '\n';
	}

	return 0;
}
