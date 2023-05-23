#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 0;
    string tmp1 = to_string(a);
    string tmp2 = to_string(b);

    string tmp3 = tmp1 + tmp2;
    string tmp4 = tmp2 + tmp1;
    if(stoi(tmp3)>stoi(tmp4))
    {
        return stoi(tmp3);
    }
    else
    {
        return stoi(tmp4);
    }

    return answer;
}

int main()
{
    cout << solution(9, 91);

    return 0;
}