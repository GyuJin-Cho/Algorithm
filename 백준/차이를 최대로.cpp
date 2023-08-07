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
	vector<int> Num;
	Num.resize(N);
	vector<int> IndexNum;
	for (int i = 0; i < N; i++)
	{
		IndexNum.push_back(i);
		cin >> Num[i];
	}
	sort(Num.begin(), Num.end());
	int answer = -217400000;
	do
	{
		int sum = 0;
		for (int i = 0; i < N-1; i++)
		{
			sum = sum + abs((Num[i] - Num[i + 1]));
		}
		answer = max(answer, sum);

	} while (next_permutation(Num.begin(), Num.end()));

	cout << answer;
	return 0;
}