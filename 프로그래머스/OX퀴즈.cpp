#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz)
{
    vector<string> answer;

    
    int result;
    int i, j;
    
    for(i=0;i<quiz.size();i++)
    {
        string num1="", num2="";
        char cacul = NULL;
        bool check = false;
	    for(j=0;j<quiz[i].size();j++)
	    {
		    if(quiz[i][j]>='0'&&quiz[i][j]<='9')
		    {
                if (!check)
                    num1 += quiz[i][j];
                else
                    num2 += quiz[i][j];
		    }
            else if(quiz[i][j]=='-'||quiz[i][j]=='+')
            {
                if(num1 == "")
                {
                    num1 += quiz[i][j];
                    continue;
                }
                if(cacul!=NULL)
                {
                    num2 += quiz[i][j];
                    continue;
                }
                cacul = quiz[i][j];
                check = true;
            }
            else if(quiz[i][j]=='=')
            {
                break;
            }
	    }
        string temp = "";
        for(int z=j+1;z<quiz[i].size();z++)
        {
	        if(quiz[i][z]==' ')
                continue;

            temp += quiz[i][z];
        }
        result = stoi(temp);
        int caculation = 0;

        if (cacul == '-')
            caculation = stoi(num1) - stoi(num2);
        else
            caculation = stoi(num1) + stoi(num2);
        if (caculation == result)
            answer.push_back("O");
        else
            answer.push_back("X");

    }

    return answer;
}

int main()
{
    vector<string> quiz={ "3 - 4 = -3", "5 + 6 = 11" };
    vector<string> a = solution(quiz);
    for (auto i : a)
        cout << i << " ";


    return 0;
}