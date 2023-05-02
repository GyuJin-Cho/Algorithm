#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    vector<int> answer;

    if(k%2==1)
    {
	    for(auto i : arr)
	    {
            answer.push_back(i * k);
	    }
    }
    else
    {
        for (auto i : arr)
        {
            answer.push_back(i + k);
        }
    }

    return answer;
}

int main()
{
    vector<int> v = { 1,2,3,100,99,98 };
    vector<int> answer = solution(v, 3);

    for(auto i : answer)
    {
        cout << i << ' ';
    }

    return 0;
}