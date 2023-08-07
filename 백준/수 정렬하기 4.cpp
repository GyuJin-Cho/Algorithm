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

int main()
{
	int T;
	cin >> T;
	vector<int> v(T);
	for (int i = 0; i < T; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());
	for (int& i : v)
	{
		cout << i << '\n';
	}
	return 0;
}