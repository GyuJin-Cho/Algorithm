#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
	vector<int> cost;
	int count = 0;
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++)
{
		if (budget - d[i] >= 0)
		{
			budget -= d[i];
			count++;
		}
		else
		{
			break;
		}
	}
	int answer = count;
	return answer;
}

int main()
{
	vector<int> d = { 99999,2,5000,4998 };
	int budget = 10000;
	cout << solution(d, budget);
	system("Pause");
	return 0;
}