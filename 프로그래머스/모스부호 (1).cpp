#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<string> mos = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
string solution(string letter)
{
    string answer = "";
    unordered_map<string, char> um;
    int ch = 0;
    for(char i='a';i<='z';i++)
    {
        um[mos[ch]] = i;
        ch++;
    }
    string tmp = "";
    for(int i=0;i<letter.size();i++)
    {
	    if(letter[i]==' ')
	    {
            answer += um[tmp];
            tmp = "";
            continue;
	    }
        tmp += letter[i];

    }
    if(!tmp.empty())
    {
        answer += um[tmp];
    }
    return answer;
}

int main()
{
    cout << solution(".--. -.-- - .... --- -.");

    return 0;
}