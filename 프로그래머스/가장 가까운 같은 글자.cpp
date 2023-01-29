#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;

    for(int i=0;i<s.size();i++)
    {
        int cnt = 0;
        bool check = false;
	    for(int j=i-1;j>=0;j--)
	    {
            cnt++;
		    if(s[i]==s[j])
		    {
                check = true;
                answer.push_back(cnt);
                break;
		    }
	    }
        if (!check)
            answer.push_back(-1);
    }

    return answer;
}

int main()
{
    vector<int> a = solution("foobar");
    for (auto i : a)
        cout << i << " ";

    return 0;
}