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
int a[1001];
int d[1001];
int d2[1001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}


	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if(a[j]<a[i]&&d[j]+1>d[i])
			{
				d[i] = d[j] + 1;
			}
		}
	}

	for (int i = n; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j] && d2[j] + 1 > d2[i])
			{
				d2[i] = d2[j] + 1;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer = max(answer, d[i] + d2[i] - 1);
	}
	cout << answer;
	return 0;
}