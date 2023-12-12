#include <vector>
#include <iostream>
class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
		std::vector<int> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			int one = nums[i];
			for(int j=i+1;j<nums.size();j++)
			{
				int two = nums[j];
				if(one+two==target)
				{
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
		}
		return ans;
    }
};

int main()
{
	Solution s;
	std::vector<int> num = { 3,2,4 };
	std::vector<int> ans = s.twoSum(num, 6);
	for (auto i : ans)
		std::cout << i << ' ';

	return 0;
}