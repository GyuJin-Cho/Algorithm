#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;
bool check[32];
int solution(int n, vector<int> lost, vector<int> reserve)
{
	int student[32];
	int answer = 0;
	//	fill(student, student + 32, 1);
	for (int i = 0; i < 32; i++)
	{
		student[i] = 1;
	}
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	int size_lost = lost.size();
	int size_reserve = reserve.size();
	for (int i = 1; i <= n; i++)
	{
		check[i] = true;
	}
	for (int i = 0; i < size_lost; i++)
	{
		student[lost[i]]--;
		check[lost[i]] = false;
	}
	for (int i = 0; i < size_reserve; i++)
	{
		student[reserve[i]]++;
		check[reserve[i]] = true;
	}
	for (int i = 0; i < size_reserve; i++)
	{
		if (student[reserve[i]] == 2)
		{
			if (student[reserve[i] - 1] == 0)
			{
				student[reserve[i]] = 1;
				student[reserve[i] - 1] = 1;
				check[reserve[i] - 1] = true;
			}
			else if (student[reserve[i] + 1] == 0)
			{
				student[reserve[i]] = 1;
				student[reserve[i] + 1] = 1;
				check[reserve[i] + 1] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == true)
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	vector<int> l = { 2,4 };
	vector<int> r = { 1,3,5 };
	cout << solution(5, l, r);

	return 0;
}