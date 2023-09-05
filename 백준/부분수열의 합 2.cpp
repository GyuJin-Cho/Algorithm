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
int N, S;
int arr[41];
map<int, int> total;
long long answer;

void left(int s, int sum)
{
	if(s==N/2)
	{
		total[sum]++;
		return;
	}
	left(s + 1, sum);
	left(s + 1, sum + arr[s]);
}

void right(int s, int sum)
{
	if (s == N)
	{
		answer += total[S - sum];
		return;
	}
		
	right(s + 1, sum);
	right(s + 1, sum + arr[s]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	left(0, 0);
	right(N / 2, 0);
	if (S == 0)
		cout << answer - 1;
	else
		cout << answer;
	return 0;
}