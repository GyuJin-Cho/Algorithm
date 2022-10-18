#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	int N, X;
	cin >> N >> X;
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	vector<int> Sum;
	int temp = 0;
	for (int i = 0; i < X; i++)
	{
		temp += arr[i];
	}
	Sum.push_back(temp);

	for (int i = 1; i <= N - X; i++)
	{
		Sum.push_back(Sum[i - 1] - arr[i - 1] + arr[X + i - 1]);
	}

	sort(Sum.begin(), Sum.end(),cmp);

	int cnt = 1;

	if (Sum[0] == 0)
	{
		cout << "SAD";
		return 0;
	}
	int MaxValue = Sum[0];
	for (int i = 1; i < Sum.size(); i++)
	{
		if (MaxValue == Sum[i])
			cnt++;
		else
			break;
	}
	cout << MaxValue << '\n' << cnt;
	return 0;
}