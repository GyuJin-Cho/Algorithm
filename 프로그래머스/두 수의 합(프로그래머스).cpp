#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b)
{
    string answer = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int up = 0;
    while (i >= 0 || j >= 0 || up > 0)
    {
        int sum = up;
        if (i >= 0)
        {
            sum += (a[i] - '0');
            i--;
        }
        if (j >= 0) 
        {
            sum += (b[j] - '0');
            j--;
        }
        up = sum / 10;
        answer += to_string(sum % 10);
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    cout << solution("18446744073709551615", "287346502836570928366");

    return 0;
}