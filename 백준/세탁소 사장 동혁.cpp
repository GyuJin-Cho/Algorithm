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
	int num;
	while (T--)
	{
		vector<int> coin;
		cin >> num;
		if (num >= 25)
		{
			coin.push_back(num / 25);
			num = num - ((num / 25) * 25);
		}
		else
		{
			coin.push_back(0);
		}
		if (num >= 10)
		{
			coin.push_back(num / 10);
			num = num - ((num / 10) * 10);
		}
		else
		{
			coin.push_back(0);
		}
		if (num >= 5)
		{
			coin.push_back(num / 5);
			num = num - ((num / 5) * 5);
		}
		else
		{
			coin.push_back(0);
		}
		if (num >= 1)
		{
			coin.push_back(num / 1);
			num = num - ((num / 1) * 1);
		}
		else
		{
			coin.push_back(0);
		}
		for (auto i : coin)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}