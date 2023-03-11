#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    vector<int> v;
    string temp = "";
    for(int i=0;i<s.size();i++)
    {
	    if(s[i]>='0'&&s[i]<='9')
	    {
            temp += s[i];
	    }
        else if(s[i]=='-')
        {
            temp += s[i];
        }
        else if(s[i]=='Z')
        {
            if (!v.empty())
                v.pop_back();
            i++;
        }
        else
        {
            v.push_back(stoi(temp));
            temp = "";
        }
    }

    if (temp != "")
        v.push_back(stoi(temp));

    for (auto i : v)
        answer += i;

    return answer;
}

int main()
{
    cout << solution("-1 -2 -3 Z");

	return 0;
}