#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string binomial)
{
    string tmp1 = "";
    string tmp2 = "";
    bool check = false;
    char op;
    for(int i=0;i<binomial.size();i++)
    {
	    if(binomial[i]>='0'&&binomial[i]<='9')
	    {
            if (!check)
                tmp1 += binomial[i];
            else
                tmp2 += binomial[i];
	    }
        else if(binomial[i]=='+'||binomial[i]=='-'||binomial[i]=='*')
        {
            check = true;
            op = binomial[i];
        }

    }
    int answer = 0;
    if(op=='-')
    {
        answer = stoi(tmp1) - stoi(tmp2);
    }
    else if(op=='+')
    {
        answer = stoi(tmp1) + stoi(tmp2);
    }
    else
    {
        answer = stoi(tmp1) * stoi(tmp2);
    }
    return answer;
}

int main()
{
    cout << solution("40000 * 40000");

    return 0;
}