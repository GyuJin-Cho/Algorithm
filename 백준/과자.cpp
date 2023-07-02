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
	int K, N, M;
	cin >> K >> N >> M;

	int cost = K * N;
	if (M >= cost)
		cout << 0;
	else
	{
		cout << abs(cost - M);
	}

	return 0;
}