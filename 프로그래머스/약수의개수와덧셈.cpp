#include <string>
#include <vector>
#include <iostream>
using namespace std;

int map[1001];

void init(int left, int right)
{
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        map[count] = i;
        count++;
    }
}

int solution(int left, int right)
{
    int answer = 0;
    int count = 0;
    init(left, right);
    for (int i = 0; i<right - left+1; i++)
    {
        for (int j = 1; j <= map[i]; j++)
        {
            if(map[i]%j==0)
            {
                count++;
            }
        }
        if (count % 2 == 0)
        {
            answer += map[i];
        }
        else
        {
            answer -= map[i];
        }
        count = 0;
    }

    return answer;
}

int main()
{
    cout << solution(24, 27);
    return 0;
}