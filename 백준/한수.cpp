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

int ArithmeticSequence(int num)
{
	int cnt = 0;

	if (num < 100)
	{
		return num;
	}
	else
	{
		cnt = 99;

		for (int i = 100; i <= num; i++)
		{
			int hun = i / 100;
			int ten = (i / 10) % 10;
			int one = i % 10;

			if ((hun - ten) == (ten - one))
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;

	const int result = ArithmeticSequence(n);
	cout << result;

	return 0;
}