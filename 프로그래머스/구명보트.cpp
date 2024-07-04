#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	sort(people.begin(), people.end());
	int i = 0;
	int j = 0;
	for (i = people.size() - 1; i > j; i--)
	{
		if (people[i] + people[j] <= limit)
		{
			j++;
			answer++;
		}
		else
		{
			answer++;
		}
	}
	if (i == j)
		answer++;
	return answer;
}

int main()
{
	vector<int> v = { 70,80,50 };
	cout << solution(v, 100);
	return 0;
}