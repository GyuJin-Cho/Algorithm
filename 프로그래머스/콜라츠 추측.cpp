#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int num)
{
    int answer = 0;
    bool check = false;
    int count = 0;
    long long n = num;
    if (num == 1)
        return 0;
    for(int i=0;i<500;i++)
    {
        if (n == 1)
        {
            check = true;
            break;
        }
	    if(n%2==0)
	    {
            n = n / 2;
            count++;
	    }
        else if(n%2!=0)
        {
            n = (n * 3) + 1;
            count++;
        }
    }

    if(check)
    {
        answer = count;
    }
    else
    {
        answer = -1;
    }

    return answer;
}

int main()
{
    cout << solution(626331);
    return 0;
}