#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int Sum[100001] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		Sum[i] = Sum[i - 1] + tmp;
	}
	int answer = -999999;
	for (int i = k; i <= n; i++)
	{
		answer = max(answer, Sum[i] - Sum[i - k]);
	}

	cout << answer;
	

	return 0;
}