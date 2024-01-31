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

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int gold = 0;

	sort(v.begin(), v.end(), greater<>());

	for(int i=1;i<n;i++)
	{
		gold += (v[0] + v[i]);
	}
	cout << gold;
	return 0;
}