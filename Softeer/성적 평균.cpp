#define _CRT_SECURE_NO_WARNINGS
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
	
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < k; i++)
	{
		int a, b;
		int cnt = 0;
		int sum = 0;
		scanf("%d%d", &a, &b);
		for (int j = a - 1; j < b; j++)
		{
			cnt++;
			sum += arr[j];
		}
		double ans = (double)sum / cnt;
		ans *= 100;
		ans = round(ans);
		ans /= 100;
		printf("%.2f", ans);
	}

	return 0;
}