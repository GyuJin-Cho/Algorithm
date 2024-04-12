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
	int n;
	cin >> n;
	vector<int> picks(n);
	for (int i = 0; i < n; i++)
		cin >> picks[i];

	vector<int> answer;
	for (int i = 0; i < n; i++)
	{
		int position = i - picks[i];
		answer.insert(answer.begin() + position, i + 1);
	}
	for (const int& ans : answer)
	{
		cout << ans << ' ';
	}
	return 0;
}