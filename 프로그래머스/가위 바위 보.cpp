#include <iostream>
#include <string>
#include <vector>
#define GAWI '2'
#define BAWI '0'
#define BO '5'
using namespace std;

string solution(string rsp)
{
    string answer = "";

    for(int i=0;i<rsp.size();i++)
    {
        if (rsp[i] == GAWI)
            answer += BAWI;
        else if (rsp[i] == BAWI)
            answer += BO;
        else
            answer += GAWI;
    }

    return answer;
}

int main()
{
    cout << solution("205");

    return 0;
}