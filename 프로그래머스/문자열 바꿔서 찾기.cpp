#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    string tmp = "";
    for(int i=0;i<myString.size();i++)
    {
        if (myString[i] == 'A')
            tmp += 'B';
        else
            tmp += 'A';
    }
    if(tmp.find(pat)==string::npos)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    cout << solution("ABBAA", "AABB");

    return 0;
}