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

	int people, num, n, count = 1;
	int answer = 0, pCount = -1;

	cin >> people;
	cin >> num;
	cin >> n;

	while (1) 
	{
		for (int i = 0; i < ((count + 1) * 2) + 4; i++)
		{
			pCount++;

			if (i < 4 && i % 2 == 0 && n == 0)
				answer++;


			else if (i < 4 && i % 2 == 1 && n == 1)
				answer++;

			else if (i >= 4 && i < count + 5 && n == 0)
				answer++;

			else if (i >= count + 5 && n == 1)
				answer++;

			if (answer == num)
				break;
		}

		if (answer == num)
			break;

		count++;
	}

	answer = pCount % people;

	cout << answer;

	return 0;
}