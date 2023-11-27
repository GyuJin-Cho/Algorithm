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
int arr[101];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = 0;
	for(int i=n-1;i>=1;i--)
	{
		while(arr[i]<=arr[i-1])
		{
			arr[i - 1] -= 1;
			ans++;
 		}
	}
	cout << ans;
	return 0;
}