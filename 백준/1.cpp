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
	int n;
	while (cin >> n)
	{
		int num = 0;
		for (int i = 1;; i++)
		{
			num = num * 10 + 1;
			num %= n;
			if (num == 0)
			{
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}