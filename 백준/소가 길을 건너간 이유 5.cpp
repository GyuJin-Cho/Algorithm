#include<iostream>

using namespace std;
int Road[100001];
bool Break[100001];
int main()
{
	cin.tie(0);
	cout.tie(0);
	int N, K, B;
	cin >> N >> K >> B;
	int a;
	for (int i = 0; i < B; i++)
	{
		cin >> a;
		Break[a] = true;
	}
	int ans = 99999999;
	for (int i = 1; i <= N - K + 1; i++)
	{
		int cnt = 0;
		for (int j = i; j < i+K; j++)
		{
			if (Break[j])
			{
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;

	return 0;
}