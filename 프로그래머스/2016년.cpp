#include <string>
#include <vector>
#include <iostream>

using namespace std;
string month[] = { "FRI","MON","TUE","FRI","SUN","WED","FRI","MON","THU","SAT","TUE","THU" };
string day[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
string solution(int a, int b)
{
   
    string answer = "";
    answer=month[a - 1];
    if (b == 1)
    {
        return answer;
    }
    int count = 0;
    for (int i = 0; i < 7; i++)
    {
        count = i;
        if (answer == day[i])
            break;
    }
    
    for (int i = 0; i < b; i++)
    {
        
        if (day[count] == "SAT")
        {
            answer = day[count];
            count = 0;
            continue;
        }
        answer = day[count];
        count++;
    }
    return answer;
}

int main()
{
    cout << solution(5, 24);
    return 0;
}