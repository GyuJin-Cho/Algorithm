#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r)
{
    vector<int> answer;

    for(int i=l;i<=r;i++)
    {
        string tmp = to_string(i);
        bool check = true;
        for(int j=0;j<tmp.size();j++)
        {
	        if(tmp[j]=='5')
                continue;
            else if(tmp[j]=='0')
                continue;
            else if(tmp[j]<='4'||tmp[j]>='6')
            {
                check = false;
                break;
            }
        }
        if (check)
            answer.push_back(i);
    }
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}

int main()
{
    vector<int> ans = solution(1, 1000000);
    for (auto i : ans)
        cout << i << ' ';

    return 0;
}