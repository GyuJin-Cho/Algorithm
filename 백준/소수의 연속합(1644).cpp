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
bool ch[4000001];
int main()
{
	int n;
	cin >> n;


	vector<int> p;
	for(int i=2;i<=n;i++)
	{
		if(!ch[i])
		{
			p.push_back(i);
			for(int j=i*2;j<=n;j+=i)
			{
				ch[j] = true;
			}
		}
	}

	int start = -1;
	int end = -1;
	int sum = 0;
	int cnt = 0;
	int size = p.size();
	while(start<=end&&end<size)
	{
		if(sum<n)
		{
			end++;
			if (end < size)
				sum += p[end];
		}
		else if(sum>n)
		{
			start++;
			if (start < size)
				sum -= p[start];
		}
		else if(sum==n)
		{
			cnt++;
			end++;
			if (end < size)
				sum += p[end];
		}
	}
	cout << cnt;
	return 0;
}