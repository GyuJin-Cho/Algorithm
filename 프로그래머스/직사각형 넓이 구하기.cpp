#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots)
{
    int answer = 0;

    int X=-1, Y=-1;

    for(int i=0;i<dots.size();i++)
    {
	    for(int j=0;j<dots.size();j++)
	    {
            X = max(X, abs(dots[i][0] - dots[j][0]));
	    }
    }

    for (int i = 0; i < dots.size(); i++)
    {
        for (int j = 0; j < dots.size(); j++)
        {
            Y = max(Y, abs(dots[i][1] - dots[j][1]));
        }
    }

    answer = X * Y;

    return answer;
}

int main()
{
    vector<vector<int>> dots = { {-1,-1},{1,1},{1,-1},{-1,1} };

    cout << solution(dots);

    return 0;
}