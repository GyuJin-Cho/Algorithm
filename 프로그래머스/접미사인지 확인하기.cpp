#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(string my_string, string is_suffix)
{
    int answer = 0;
    map<string, int>m;
    int Size = my_string.size();
    string tmp="";
    for(int i=0;i<Size;i++)
    {
        tmp = my_string;
        m[tmp]++;
        my_string.erase(my_string.begin(), my_string.begin() + 1);
    }

    if(m[is_suffix]>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }



    return answer;
}

int main()
{
    cout << solution("banana", "abanana");

    return 0;
}