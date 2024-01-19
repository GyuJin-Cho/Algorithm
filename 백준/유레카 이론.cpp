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
int arr[1001];

bool ch(int num)
{
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			for(int k=1;k<=50;k++)
			{
				if (arr[i] + arr[j] + arr[k] == num)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	int T,n;
	cin >> T;
	for (int i = 1; i <= 1000; i++)
		arr[i] = arr[i - 1] + i;
	while(T--)
	{
		cin >> n;
		cout << ch(n) << '\n';
	}

	return 0;
}