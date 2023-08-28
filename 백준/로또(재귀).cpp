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
vector<int> lotto;
void DFS(const vector<int> &a, int index, int cnt)
{
	if(cnt==6)
	{
		for(int& num : lotto)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}
	int n = a.size();
	if (n == index)
		return;
	lotto.push_back(a[index]);
	DFS(a, index + 1, cnt + 1);
	lotto.pop_back();
	DFS(a, index + 1, cnt);
}

int main()
{
	while(true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		DFS(a, 0, 0);
		cout << '\n';
	}

	return 0;
}