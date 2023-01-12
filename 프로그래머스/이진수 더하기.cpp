#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string bin1, string bin2)
{
    string answer = "";
    int a = 0, b = 0;
    int cnt = 1;
    for(int i=bin1.size()-1;i>=0;i--)
    {
        a = a + ((bin1[i] - 48) * cnt);
        cnt *= 2;
    }
    cnt = 1;
    for(int i=bin2.size()-1;i>=0;i--)
    {
        b = b + ((bin2[i] - 48) * cnt);
        cnt *= 2;
    }

    int sum = a + b;
    if (sum == 0)
        return "0";
    while(sum!=0)
    {
        answer += to_string(sum % 2);
        sum /= 2;
    }
    reverse(answer.begin(), answer.end());

    return answer;
}
int main()
{
    cout << solution("0", "0");

	return 0;
}