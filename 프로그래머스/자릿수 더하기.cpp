#include <iostream>
#include <vector>
using namespace std;
int solution(int n)
{
    int answer = 0;
    vector<int> a;
    while(true)
    {
        a.push_back(n % 10);
        n = n / 10;
        if (n == 0)
            break;
    }
    for(int i=0;i<a.size();i++)
    {
        answer += a[i];
    }

    return answer;
}

int main()
{
    cout << solution(987);
    return 0;
}