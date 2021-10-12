#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int solution(vector<vector<int>> sizes)
{
	int answer = 0;
	int Max1 = 0;
	int Max2 = 0;
	
	for (int i = 0; i < sizes.size(); i++)
	{
		sort(sizes[i].begin(), sizes[i].end());
	}

	for (int i = 0; i < sizes.size(); i++)
	{
		Max1 = max(Max1, sizes[i][0]);
		Max2 = max(Max2, sizes[i][1]);
	}
	answer = Max1 * Max2;
	return answer;
}

int main()
{
	vector<vector<int>> a = { {60,50},{30,70},{60,30},{80,40} };
	cout << solution(a);
	return 0;
}