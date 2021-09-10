#include<iostream>
#include<cmath>
using namespace std;

long long solution(int price, int money, int count)
{
    long long pri = 0;
    long long sumPrice=0;
    long long answer = 0;
    for(int i=1;i<=count;i++)
    {
        pri = price * i;
        sumPrice += pri;
    }
    long long tmp = money - sumPrice;
    if(tmp>=0)
    {
        answer = 0;
    }
    else
    {
        answer = abs(tmp);
    }
    return answer;

}

int main()
{
    long long a = solution(3, 20, 4);
    cout << a;
	return 0;
}