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

using namespace std;
int Paper[101][101];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int x, y;
		cin >> x >> y;
		for (int i = y; i < y + 10; i++)
			for (int j = x; j < x + 10; j++)
				Paper[i][j] = 1;
	}

	int answer = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (Paper[i][j] == 1)
				answer++;
	cout << answer;

	return 0;
}