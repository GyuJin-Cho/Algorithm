#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(string my_string)
{
    int answer = 0;

    bool change = false;
    string tmp = "";
    queue<char> q;
    vector<string> numbers; 
    for(int i=0;i<my_string.size();i++)
    {
        if(!change)
        {
            if(my_string[i] == ' ')
            {
                numbers.push_back(tmp);
                tmp = "";
                change = true;
            }
            else
            {
                tmp += my_string[i];
            }
        }
        else
        {
            if (my_string[i] == ' ')
            {
                change = false;
            }
            else
            {
                q.push(my_string[i]);
            }
        }
    }

    if (tmp != "")
        numbers.push_back(tmp);

    if(q.front() == '+')
    {
        answer = stoi(numbers[0]) + stoi(numbers[1]);
        q.pop();
        numbers.erase(numbers.begin(), numbers.begin() + 2);
    }
    else
    {
        answer = stoi(numbers[0]) - stoi(numbers[1]);
        q.pop();
        numbers.erase(numbers.begin(), numbers.begin() + 2);
    }

    while (true)
    {
        if (numbers.empty() || q.empty())
            break;
        if (q.front() == '+')
        {
            answer = answer+ stoi(numbers[0]);
            q.pop();
            numbers.erase(numbers.begin(), numbers.begin() + 1);
        }
        else
        {
            answer = answer - stoi(numbers[0]);
            q.pop();
            numbers.erase(numbers.begin(), numbers.begin() + 1);
        }
    }

    return answer;
}

int main()
{
    cout << solution("100 - 50 + 40 - 50");

    return 0;
}