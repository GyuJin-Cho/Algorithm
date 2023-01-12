#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> dot)
{
    int answer = 0;
    if (dot[0] >= 0 && dot[1] >= 0)
        return 1;
    else if (dot[0] < 0 && dot[1] >= 0)
        return 2;
    else if (dot[0] < 0 && dot[0] < 0)
        return 3;
    else
        return 4;

    return answer;
}

int main()
{
    vector<int> dot = { 7,-9 };

    cout << solution(dot);

    return 0;
}