#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int a, int b, int c, int d)
{
    vector<int> nums{ a,b,c,d };
    set<int> counts{ a,b,c,d };
    sort(nums.begin(), nums.end());

    switch (counts.size())
	{
    case 1:
        return 1111 * nums[0];
    case 2:
        if (nums[1] != nums[2]) 
        {
            return (nums[3] + nums[0]) * (nums[3] - nums[0]);
        }
        else 
        {
            if (nums[0] == nums[1])
            {
                return pow((10 * nums[0] + nums[3]), 2);
            }
            else 
            {
                return pow((10 * nums[3] + nums[0]), 2);
            }
        }
    case 3:
        if (nums[0] == nums[1]) { return nums[2] * nums[3]; }
        if (nums[0] == nums[2]) { return nums[1] * nums[3]; }
        if (nums[0] == nums[3]) { return nums[1] * nums[2]; }
        if (nums[1] == nums[2]) { return nums[0] * nums[3]; }
        if (nums[1] == nums[3]) { return nums[0] * nums[2]; }
        if (nums[2] == nums[3]) { return nums[0] * nums[1]; }
    case 4:
        return nums[0];
    }
}

int main()
{
    cout << solution(2,2,2,2);

    return 0;
}