#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
   
    vector<int> answer;

    int r = 0;
    int c = 0;

    for (long long i = left; i < right+1 ; i++)
    {
        r = i / n;
        c = i % n;

        if (r >= c + 1)
        {
            c += r - c;
        }

        answer.push_back(c + 1);
    }

    return answer;
}

int main()
{
    vector<int> v = solution(3, 2, 5);

    for (auto i : v)
        cout << i;

    return 0;
}