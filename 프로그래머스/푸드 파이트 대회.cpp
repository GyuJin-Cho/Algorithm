#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    queue<int> n1;
    stack<int> n2;
    for(int i=1;i<food.size();i++)
    {
        if(food[i]%2==1)
        {
			if(food[i]==1)
                continue;

            for(int j=0;j<(food[i]-1)/2;j++)
            {
                n1.push(i);
            }

        }
        else
        {
            for (int j = 0; j < food[i] / 2; j++)
            {
                n1.push(i);
            }
        }
    }

    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] % 2 == 1)
        {
            if (food[i] == 1)
                continue;

            for (int j = 0; j < (food[i] - 1) / 2; j++)
            {
                n2.push(i);
            }

        }
        else
        {
            for (int j = 0; j < food[i] / 2; j++)
            {
                n2.push(i);
            }
        }
    }
    while(!n1.empty())
    {
        answer += to_string(n1.front());
        n1.pop();
    }
    answer += '0';
    while (!n2.empty())
    {
        answer += to_string(n2.top());
        n2.pop();
    }

    return answer;
}

int main()
{
    vector<int> food = { 1,7,1,2 };
    cout << solution(food);

    return 0;
}