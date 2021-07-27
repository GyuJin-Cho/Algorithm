#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    answer.push_back(arr[0]);
    int del = 0;
    for (int i = 1; i < arr.size(); i++) 
    {
        int x = answer[del];
        int y = arr[i];

        if (x == y) 
        {
            continue;
        }
        else 
        {
            answer.push_back(arr[i]);
            del++;
        }
    }
    return answer;
}

int main()
{
    vector<int> answer = { 1,1,3,3,0,1,1 };
    vector<int> a = solution(answer);
    for (auto c : a)
    {
        cout << c<<" ";
    }
    return 0;
}