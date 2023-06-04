#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v;
	int ans = -2174000;
	vector<int> ansV;

	for(int i=N;i>=0;i--)
	{
		int start = 0;
		int end = 1;
		v.clear();
		v.push_back(N);
		v.push_back(i);
		while(0<=v[start]-v[end])
		{
			v.push_back(v[start] - v[end]);
			start++;
			end++;
		}
		int size = v.size();
		if(size>ans)
		{
			ansV = v;
			ans = v.size();
		}
	}
	cout << ans << '\n';
	for(auto i : ansV)
	{
		cout << i << ' ';
	}
	return 0;
}