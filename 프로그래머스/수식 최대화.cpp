#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long caculator(long long a, long long b, char c)
{
    if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else
        return a + b;
}

long long solution(string expression)
{
    long long answer = 0;
    string s = expression;
    vector<char> pcal = { '*','-','+' };
    vector<long long> num;
    vector<char> cal;
    sort(pcal.begin(), pcal.end());
    string tmp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
            tmp += s[i];
        else
        {
            num.push_back(stoll(tmp));
            cal.push_back(s[i]);
            tmp = "";
        }
    }
    num.push_back(stoll(tmp));
    long long Max = -21740000;

    do
    {
        vector<long long> n = num;
        vector<char> c = cal;
        for(int i=0;i<3;i++)
        {
	        for(int j=0;j<c.size();)
	        {
                if (pcal[i] == c[j])
                {
                    long long result = caculator(n[j], n[j + 1], c[j]);
                    n.erase(n.begin() + j, n.begin() + j + 2);
                    c.erase(c.begin() + j);
                    n.insert(n.begin() + j, result);
                }
                else
                    j++;
	        }
        }
        Max = max(Max, abs(n[0]));
    } while (next_permutation(pcal.begin(), pcal.end()));
    answer = Max;
    return answer;
}

int main()
{
    cout << solution("50*6-3*2");

    return 0;
}