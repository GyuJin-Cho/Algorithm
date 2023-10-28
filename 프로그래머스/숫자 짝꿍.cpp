#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    vector<int>arrX(10, 0);
    vector<int>arrY(10, 0);
    for (auto i : X)
        arrX[i - 48]++;
    for (auto i : Y)
        arrY[i - 48]++;
    for(int i=0;i<10;i++)
    {
        answer += string(arrX[i] > arrY[i] ? arrY[i] : arrX[i], i + 48);
    }
    sort(answer.begin(), answer.end(), greater<int>());
    if (answer.size() == 0)
        answer = "-1";
    else if (count(answer.begin(), answer.end(), '0') == answer.size())
        answer = "0";
    return answer;
}

int main()
{
    cout << solution("12321", "42531");

    return 0;
}