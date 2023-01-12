#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
    int answer = 2;
    sort(spell.begin(), spell.end());
    for (int j = 0; j < dic.size(); j++)
    {
        sort(dic[j].begin(), dic[j].end());
    }

    string s;
    for (int i = 0; i < spell.size(); i++)
        s += spell[i];

    for(int i=0;i<dic.size();i++)
    {
	    if(s==dic[i])
	    {
            return 1;
	    }
    }

    return answer;
}

int main()
{
    vector<string> spell = { "z", "d", "x" };
    vector<string> dic = { "def", "dww", "dzx", "loveaw" };

    cout << solution(spell, dic);

    return 0;
}