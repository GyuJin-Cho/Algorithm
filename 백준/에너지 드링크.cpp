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
	vector<int> items(n);
	int itemmax = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i];
		if (items[i] > itemmax)
			itemmax = items[i];
	}

	sort(items.begin(), items.end());
	queue<float> energy;
	for(int i=0;i<n;i++)
	{
		if(items[i]==itemmax)
			continue;
		energy.push(float(items[i]));
	}
	float ans = float(itemmax);
	while(!energy.empty())
	{
		ans += (energy.front() / 2.0f);
		energy.pop();
	}
	cout << ans;
	return 0;
}