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
	int n, b;
	cin >> n >> b;

	string num;
	while (n != 0)
	{
		int tmp = n % b;
		if (tmp > 9)
		{
			tmp = tmp - 10 + 'A';
			num += tmp;
		}
		else
		{
			num += ('0' + tmp);
		}
		n /= b;
	}
	reverse(num.begin(), num.end());

	cout << num;
	return 0;
}