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
int n, k, leaf = 0, root;
vector<int> tree[51];

int DFS(int node)
{
	if (node == k)
		return -1;
	if(tree[node].size()==0)
	{
		leaf++;
		return 0;
	}
	for(int i=0;i<tree[node].size();i++)
	{
		int temp = DFS(tree[node][i]);
		if (temp == -1 && tree[node].size() == 1)
			leaf++;
	}
	return 0;
}

int main()
{
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int num;
		cin >> num;
		if (num == -1)
			root = i;
		else
			tree[num].push_back(i);
	}
	cin >> k;
	DFS(root);
	cout << leaf;
	return 0;
}