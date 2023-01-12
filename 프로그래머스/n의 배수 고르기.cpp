#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist)
{
    vector<int> answer;

    for(int i=0;i< numlist.size();i++)
    {
        if (numlist[i] % n == 0)
            answer.push_back(numlist[i]);
    }

    return answer;
}

int main()
{
    vector<int> numlist={4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<int> a = solution(3,numlist);

    for (auto i : a)
        cout << i << " ";

    return 0;
}