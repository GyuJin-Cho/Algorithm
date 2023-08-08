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
	string num;
	int n;
	cin >> num >> n;

	int sum = 0;
	for (int i = 0; i < num.size(); i++)
	{
		int tmp = num[num.size() - (i + 1)];
		if ('0' <= tmp && tmp <= '9')
		{
			tmp = tmp - '0';
		}
		else
		{
			tmp = tmp + 10 - 'A';
		}
		sum += (tmp * (int)pow(n, i));
	}
	cout << sum;
	return 0;
}