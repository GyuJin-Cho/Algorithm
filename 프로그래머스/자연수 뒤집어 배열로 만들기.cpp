#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(long long n)
{
    vector<int> answer;
    while (true)
    {
        answer.push_back(n % 10);  
        n = n / 10;                
        if (n == 0)
        {
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> a = solution(12345);
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}