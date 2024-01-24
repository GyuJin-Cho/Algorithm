#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k)
{
    int answer = 0;
    
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(i+j<=k)
            {
                answer+=board[i][j];
            }

        }
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 2},{1, 2, 3},{2, 3, 4},{3, 4, 5}};
    cout<<solution(v, 2);
    return 0;
}
