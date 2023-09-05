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
	cin >> n;

	vector<bool> c(n + 1);
	vector<int> p;
	for(int i=2;i<=n;i++)
	{
		if(!c[i])
		{
			p.push_back(i);
			for(int j=i*2;j<=n;j+=i)
			{
				c[j] = true;
			}
		}
	}


	int l = -1;
	int r = -1;
	int sum = 0;
	int answer = 0;
	int size = p.size();
	while(l<=r&&r<size)
	{
		if (sum == n)
		{
			answer++;
			r++;
			if(r<p.size())
				sum += p[r];
			
		}
		else if(sum<n)
		{
			r++;
			if(r<p.size())
				sum += p[r];
		}
		else
		{
			l++;
			sum -= p[l];
		}
	}
	cout << answer;
	return 0;
}