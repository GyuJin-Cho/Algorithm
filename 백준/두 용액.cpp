#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	int a;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = n - 1;
	int answer_one, answer_two;
	int answer = 2000000000;
	while (start < end)
	{
		int result = v[start] + v[end];
		if (answer > abs(result))
		{
			answer_one = v[start];
			answer_two = v[end];
			answer = abs(result);
			if (result == 0)
				break;
		}

		if (result < 0)
		{
			start++;
		}
		else
		{
			end--;
		}

	}

	cout << answer_one << " " << answer_two;

	return 0;
}