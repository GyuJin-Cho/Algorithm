#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int size = nums.size();
	int select = size / 2;
	set<int> a;
	for (int i = 0; i < size; i++)
	{
		a.insert(nums[i]);
	}

	if (a.size() >= select)
	{
		answer = select;
	}
	else
	{
		answer=a.size();
	}

	
	return answer;
}