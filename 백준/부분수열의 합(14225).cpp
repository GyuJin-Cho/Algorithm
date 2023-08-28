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
vector<bool> ch(20 * 100000 + 10);
void DFS(const vector<int>& a, int index,int sum)
{
	if(index==n)
	{
		ch[sum] = true;
		return;
	}
	DFS(a, index + 1, sum + a[index]);
	DFS(a, index + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	DFS(a, 0, 0);
	for(int i=1;;i++)
	{
		if(!ch[i])
		{
			cout << i;
			break;
		}
	}
	return 0;
}