#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int c;

bool cmd(vector<int> v1, vector<int> v2)
{
    if (v1[c-1] == v2[c-1])
    {
        return v1 > v2;
    }
    return v1[c-1] < v2[c-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    c = col;
    sort(data.begin(), data.end(), cmd);
    int tmp = 0;
    for(int i=row_begin-1;i<row_end;i++)
    {
        tmp = 0;
	    for(int j=0;j<data[i].size();j++)
	    {
            tmp += (data[i][j] % (i+1));
	    }
        answer ^= tmp;
    }
    

    return answer;
}

int main()
{
    vector<vector<int>> data = { {2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3} };
    cout << solution(data, 2, 2, 3);
    return 0;
}