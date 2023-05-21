#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int answer = 0;

    for(int i=0;i<myString.size()-pat.size()+1;i++)
    {
        string tmp = "";
        for(int j=i;j<pat.size()+i;j++)
        {
            tmp += myString[j];
        }
        if (tmp == pat)
            answer++;
    }

    return answer;
}

int main()
{
    cout << solution("aaaa", "aa");

    return 0;
}