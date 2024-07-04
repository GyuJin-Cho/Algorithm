#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name)
{
    int answer = 0;
    int n = name.length();
    int move = name.length() - 1;
    for (int i = 0; i <n; i++)
    {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        int next = i + 1;
        while (next < n && name[next] == 'A')
            next++;

        move = min(move, i + n - next + min(i, n - next));
    }

    return answer+move;
}

int main()
{
    cout << solution("JAN");

    return 0;
}