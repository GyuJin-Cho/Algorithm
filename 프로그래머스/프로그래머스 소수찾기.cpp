#include <iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;
bool check[1000001]={false,};
int solution(int n)
{
    int answer = 0;
    for(int i=2;i<=n;i++)
    {
	    if(!check[i])
	    {
            answer++;
	    }
        for(int j=i;j<=n;j+=i)
        {
            check[j] = true;
        }
    }
    return answer;
}

int main()
{
    cout << solution(10);
    return 0;
}