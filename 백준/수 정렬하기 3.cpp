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
	vector<int>arr(10001,0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < arr[i]; j++)
			cout << i << '\n';
	return 0;
}