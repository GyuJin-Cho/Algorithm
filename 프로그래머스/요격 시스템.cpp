#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    int idx = 0;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
    while(idx<targets.size())
    {
        int end = targets[idx++][1];
        answer++;
        while (idx < targets.size()&&targets[idx][0]<end)
        {
            if (targets[idx][1] < end)
                end = targets[idx][1];
            idx++;
        }
    }

    return answer;
}

int main()
{
	vector<vector<int>> t = {{4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}};
    cout << solution(t);

    return 0;
}