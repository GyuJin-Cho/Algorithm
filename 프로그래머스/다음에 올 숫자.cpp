#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common)
{
    int answer = 0;

    if(common[2]-common[1]==common[1]-common[0])
    {
	    answer = common[common.size()-1] + (common[1] - common[0]);
    }
    else
    {
        answer = common[common.size() - 1] * (common[1] / common[0]);
    }

    return answer;
}

int main()
{
    vector<int> v = { 1,2,3,4 };
    cout << solution(v);

    return 0;
}