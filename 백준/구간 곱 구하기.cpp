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

constexpr int MAX = 1000000;
constexpr long long MOD = 1000000007;
using namespace std;
int n, m, k;
long long arr[MAX];
long long MakeSegmentTree(vector<long long>& segmenttree, int node, int start, int end)
{
	if (start == end)
	{
		return segmenttree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return segmenttree[node] = MakeSegmentTree
	(segmenttree, node * 2, start, mid) * MakeSegmentTree(segmenttree, node * 2 + 1, mid + 1, end) % MOD;
}

long long UpdateSegmentTree(vector<long long>& segmentTree, int node, int start, int end, int idx, long long diff)
{
	if (idx<start || idx > end)
		return segmentTree[node];
	if(start==end)
		return segmentTree[node] = diff;
	int mid = (start + end) / 2;
	return segmentTree[node] = UpdateSegmentTree(segmentTree, node * 2, start, mid, idx, diff) * UpdateSegmentTree(segmentTree, node * 2 + 1, mid + 1, end, idx, diff) % MOD;
}

long long MulSegmentTree(vector<long long>& segmentTree, int node, int left, int right, int start, int end)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && right >= end)
		return segmentTree[node];
	int mid = (start + end) / 2;
	return (MulSegmentTree(segmentTree, node * 2, left, right, start, mid) * MulSegmentTree(segmentTree, node * 2 + 1, left, right, mid + 1, end))%MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int treeDepth = ceil(log2(n));
	int treeSize = 1 << (treeDepth + 1);
	vector<long long> segmenttree(treeSize);

	MakeSegmentTree(segmenttree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		int order, left;
		long long right;
		cin >> order >> left >> right;
		if (order == 1)
		{
			UpdateSegmentTree(segmenttree, 1, 0, n - 1, left - 1, right);
			arr[left - 1] = right;
		}
		else
		{
			cout << MulSegmentTree(segmenttree, 1, left - 1, right - 1, 0, n - 1) << '\n';
		}
	}

	return 0;
}