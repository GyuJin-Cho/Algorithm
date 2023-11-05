#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;
    int N = balls.size();
    for(int i=0;i<N;i++)
    {
        int len, a, b;
        if(balls[i][0]==startX)
        {
            a = abs(startY - balls[i][1]);
            b = 2 * min(m - startX, startX);
            if (startY > balls[i][1])
                len = pow(a + 2 * (n - startY), 2);
            else
                len = pow(a + 2 * startY, 2);
        }
        else if(balls[i][1]==startY)
        {
            a = abs(startX - balls[i][0]);
            b = 2 * min(n - startY, startY);
            if (startX > balls[i][0])
                len = pow(a + 2 * (m - startX), 2);
            else
                len = pow(a + 2 * startX, 2);
        }
        else
        {
            a = min(startX + balls[i][0], 2 * m - startX - balls[i][0]);
            b = abs(startY - balls[i][1]);
            len = pow(a, 2) + pow(b, 2);
            a = min(startY + balls[i][1], 2 * n - startY - balls[i][1]);
            b = abs(startX - balls[i][0]);
        }
        int tmp = pow(a, 2) + pow(b, 2);
        len = min(len, tmp);
        answer.push_back(len);
    }


    return answer;
}

int main()
{
    vector<vector<int>> balls = { {7, 7}, {2, 7}, {7, 3} };
    vector<int> ans = solution(10, 10, 3, 7, balls);
    for(int i: ans)
    {
        cout << i << ' ';
    }
    return 0;
}