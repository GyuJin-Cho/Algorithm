#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    s.erase(s.begin()+1);
    s.erase(s.end()-1);
    string tmp = "";

    map<int, int>m;
    for(int i=0;i<s.length();i++)
    {
	    if(s[i]=='{'||s[i]=='}'||s[i]==',')
	    {
		    if(tmp!="")
		    {
                m[stoi(tmp)]++;
                tmp = "";
		    }
            continue;
	    }
        else
        {
            tmp += s[i];
        }
    }
    answer.resize(m.size());
    for(auto i : m)
    {
        answer[i.second - 1] = i.first;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int i : ans)
        cout << i << ' ';

    return 0;
}