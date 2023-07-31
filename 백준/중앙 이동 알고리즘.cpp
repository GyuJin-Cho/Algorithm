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
	int x = 2;
	cin >> n;
	while (n--)
	{
		x += (x - 1);
	}

	x *= x;
	cout << x;

	return 0;
}