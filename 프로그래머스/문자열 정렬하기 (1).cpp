#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string my_string)
{
    vector<int> answer;

    for(int i=0;i<my_string.size();i++)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
            answer.push_back(my_string[i] - 48);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> a = solution("hi12392");

    for (auto i : a)
        cout << i << " ";

	return 0;
}