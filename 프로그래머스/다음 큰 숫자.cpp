#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count(int n)
{
    int cnt = 0;
    while(1)
    {
        if (n % 2 != 0)
            cnt++;
        n /= 2;
        if(n==2||n==1)
        {
            cnt++;
            break;
        }
    }
    return cnt;
}

int solution(int n)
{
    int cnt = count(n);
    n++;
    while(1)
    {
	    if(cnt==count(n))
	    {
            return n;
	    }
        n++;
    }
}

int main()
{
    cout << solution(15);
    return 0;
}