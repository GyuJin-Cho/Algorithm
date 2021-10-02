#include <string>
#include <vector>
#include<iostream>


using namespace std;

string solution(string s, int n)
{
    string answer = "";
    vector<char> c;
    for(int i=0;i<s.length();i++)
    {
        c.push_back(s[i]);
    }

    for(int i=0;i<c.size();i++)
    {
	    for(int j=1;j<=n;j++)
	    {
            if(c[i]==' ')
            {
                break;
            }
            if(c[i]=='z')
            {
                c[i] = 'a';
                continue;
            }
            else if(c[i]=='Z')
            {
                c[i] = 'A';
                continue;
            }
            c[i] = c[i] + 1;
	    }
    }
    for(int i=0;i<c.size();i++)
    {
        answer += c[i];
    }
    return answer;
}

int main()
{
    cout << solution("a B z", 4);
    return 0;
}