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
int arr[100001];
int GCD(int a, int b)
{
	while(b!=0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	vector<int> v;
	for(int i=0;i<n-1;i++)
	{
		v.push_back(arr[i + 1] - arr[i]);
	}
	int gcd = GCD(v[0], v[1]);
	for(int i=2;i<v.size();i++)
	{
		gcd = GCD(gcd, v[i]);
	}

	int ans = 0;
	for(auto& i : v)
	{
		ans += i / gcd - 1;
	}
	cout << ans;
	return 0;
}