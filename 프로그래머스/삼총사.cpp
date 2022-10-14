#include<iostream>
#include<vector>
using namespace std;
int solution(vector<int> number)
{
	int answer = 0;

	for (int i = 0; i < number.size(); i++)
	{
		for (int j = i+1; j < number.size(); j++)
		{
			for (int z = j + 1; z < number.size(); z++)
			{
				int sum = number[i] + number[j] + number[z];
				if (sum == 0)
					answer++;
			}
		}
	}

	return answer;
}
int main()
{
	vector<int> v = { -1, 1, -1, 1 };
	cout << solution(v);
	return 0;
}