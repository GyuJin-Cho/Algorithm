#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;
set<string> ong;
int solution(vector<string> babbling)
{
    int answer = 0;
    ong.insert("aya");
    ong.insert("ye");
    ong.insert("woo");
    ong.insert("ma");
    
    for(int i=0;i<babbling.size();i++)
    {
        string tmp = "";
        stack<string> s;
	    for(int j=0;j<babbling[i].size();j++)
	    {
		    if(ong.find(tmp)!=ong.end())
		    {
                if (!s.empty())
                {
                    if(s.top()==tmp)
						continue;
                }
                s.push(tmp);
                tmp = "";
		    }
            tmp += babbling[i][j];
	    }
        if(ong.find(tmp)!=ong.end())
        {
            if (!s.empty())
            {
                if (s.top() == tmp)
                    continue;
            }
            tmp = "";
        }
        if(tmp.empty())
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution({ "aya", "yee", "u", "maa" });

    return 0;
}