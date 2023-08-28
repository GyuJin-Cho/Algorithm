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

int answer = 0;

int DFS(const vector<int>& a)
{
	int n = a.size();
	if (n == 2)
		return 0;
	int answer = 0;
	for(int i=1;i<n-1;i++)
	{
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		b.erase(b.begin() + i);
		energy += DFS(b);
		if (answer < energy)
			answer = energy;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << DFS(a);
	return 0;
}