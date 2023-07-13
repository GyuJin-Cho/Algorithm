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
	int n, m;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cout << n + m << '\n';
	}

	return 0;
}