#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer = num_list;

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> numlist = { 1,2,3,4,5 };
    vector<int> a = solution(numlist);

    for (auto i : a)
        cout << i << " ";

    return 0;
}