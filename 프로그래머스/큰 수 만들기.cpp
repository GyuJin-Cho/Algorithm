#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    int answersize = number.length() - k;
    int sidx = 0;
    for(int i=0;i<answersize;i++)
    {
        char maxint = number[sidx];
        int maxidx = sidx;
        for(int j=sidx;j<=k+i;j++)
        {
            if (maxint < number[j])
            {
                maxint = number[j];
                maxidx = j;
            }
        }
        sidx = maxidx + 1;
        answer += maxint;
    }

    return answer;
}

int main()
{
    cout << solution("1924",2);

    return 0;
}