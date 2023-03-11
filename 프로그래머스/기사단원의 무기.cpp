#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;
    vector<int> prime;

    for (int i = 1; i <= number; i++)
    {
        int cnt = 0;
        for(int j=1;(j*j)<=i;j++)
        {
	        if(i%j==0)
	        {
                int tmp = (int)(i / j);
                if ((tmp * tmp) == i)
                    cnt++;
                else
                    cnt += 2;
	        }
        }

        if (cnt > limit)
            answer += power;
        else
            answer += cnt;
    }

    return answer;
}

int main()
{
    cout << solution(10, 3, 2);

	return 0;
}