#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
vector<long long> V;
int N;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		V.push_back(a);
	}

	int start = 0;
	int end = V.size() - 1;
	
	int answer_one = 0, answer_two = 0;

	long long result = 9999999999999;
	while (start < end)
	{
		int sum = V[start] + V[end];
		if (result > abs(sum))
		{
			answer_one = V[start];
			answer_two = V[end];
			result = abs(sum);
			if (result == 0)
				break;
		}
		if (sum < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	cout << answer_one<<" "<<answer_two;

	return 0;
}