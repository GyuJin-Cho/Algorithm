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
const int MAX = 1000000;
int prime[MAX];
int pn;
bool check[MAX + 1];

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= MAX; i++)
	{
		if (!check[i])
		{
			prime[pn++] = i;
			for (int j = i + i; j <= MAX; j += i)
			{
				check[j] = true;
			}
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i < pn; i++)
		{
			if (!check[n - prime[i]])
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}

	return 0;
}