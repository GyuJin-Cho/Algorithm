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

int main()
{
	int N;
	cin >> N;

	int Space = N - 1;
	int Jump = 1;
	bool flag = false;
	for (int i = 0; i < N * 2 - 1; i++)
	{
		if (Space > 0&&!flag)
		{
			for (int j = 1; j <= Space; j++)
			{
				cout << ' ';
			}
			Space--;
			for (int j = 0; j < Jump; j++)
			{
				cout << '*';
			}
			cout << '\n';
			Jump += 2;
		}
		else if (Space == 0)
		{
			for (int j = 0; j < N * 2 - 1; j++)
			{
				cout << "*";
			}
			cout << '\n';
			Space++;
			Jump -= 2;
			flag = true;
		}
		else
		{
			for (int j = 1; j <= Space; j++)
			{
				cout << ' ';
			}
			Space++;
			for (int j = 0; j < Jump; j++)
			{
				cout << '*';
			}
			cout << '\n';
			Jump -= 2;
		}
	}

	return 0;
}