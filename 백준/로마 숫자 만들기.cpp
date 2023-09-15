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
bool check[50 * 20 + 1];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			for(int k=0;k<=n-i-j;k++)
			{
				int l = n - i - j - k;
				int sum = i + 5 * j + 10 * k + 50 * l;
				check[sum] = true;
			}
		}
	}
	int answer = 0;
	for(int i=1;i<=50*20;i++)
	{
		if (check[i])
			answer += 1;
	}
	cout << answer;
	return 0;
}