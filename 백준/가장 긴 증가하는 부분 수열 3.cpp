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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, num;
	cin >> n;
	vector<int> arr;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (arr.empty() || arr.back() < num)
		{
			arr.push_back(num);
			v.push_back(num);
		}
		else
		{
			vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), num);
			*iter = num;
		}
	}

	cout << arr.size() << '\n';
	return 0;
}