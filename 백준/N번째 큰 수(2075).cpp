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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> arr(N * N);
	for(int i=0;i<N*N;i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(),greater<>());
	cout << arr[N-1];
	return 0;
}