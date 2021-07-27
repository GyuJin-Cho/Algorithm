#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
	int count = 0;
	int zerocount = 0;
	for (int i = 0; i < lottos.size(); i++)
	{
		if (lottos[i] == 0)
			zerocount++;
		for (int j = 0; j < win_nums.size(); j++)
		{
			if (lottos[i] == win_nums[j])
			{
				count++;
			}
		}
	}
	if (count == 6)
		answer.push_back(1);
	else if (count == 5)
		answer.push_back(2);
	else if (count == 4)
		answer.push_back(3);
	else if (count == 3)
		answer.push_back(4);
	else if (count == 2)
		answer.push_back(5);
	else
		answer.push_back(6);
	count += zerocount;
	if (count == 6)
		answer.push_back(1);
	else if (count == 5)
		answer.push_back(2);
	else if (count == 4)
		answer.push_back(3);
	else if (count == 3)
		answer.push_back(4);
	else if (count == 2)
		answer.push_back(5);
	else
		answer.push_back(6);

	sort(answer.begin(), answer.end());
	return answer;
}

int main()
{
	vector<int> lottos = { 45, 4, 35, 20, 3, 9 };
	vector<int> win_nums = { 20, 9, 3, 45, 4, 35 };
	vector<int> answer = solution(lottos, win_nums);

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	system("Pause");
	return 0;
}