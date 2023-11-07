#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    int Len = s.length();
    int i, j;
    for(i=0;i<Len;i++)
    {
        int cntX = 0;
        int cntY = 0;
        char x = s[i];

        for(j=i;j<Len;j++)
        {
            if (s[j] == x)
                cntX++;
            else
                cntY++;
            if (cntX == cntY)
                break;
        }
        i = j;
        answer++;
    }

    return answer;
}

int main()
{
    cout << solution("aaabbaccccabba");

    return 0;
}