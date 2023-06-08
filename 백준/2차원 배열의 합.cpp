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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> arr(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	int K;
	cin >> K;
	while(K--)
	{
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int sum = 0;
		for (int i = a; i <= x; i++)
			for (int j = b; j <= y; j++)
				sum += arr[i][j];
		cout << sum << '\n';
	}

	return 0;
}