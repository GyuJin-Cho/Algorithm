#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long point(long long i, long long d)
{
    long long left = 1, right = d, mid;
    long long ans;
    while(left<=right)
    {
        mid = (left + right) / 2;
        if(mid*mid+i*i<=d*d)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}


long long solution(int k, int d)
{
    long long answer = d/k+1;
    for(long long i = 0;i<d;i+=k)
    {
        answer += point(i, d) / k;
    }


    return answer;
}

int main()
{
    cout << solution(2, 4);
    return 0;
}