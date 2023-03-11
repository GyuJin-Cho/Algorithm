#include <iostream>
#include <string>
#include <vector>

using namespace std;
int Map[101][101];
int solution(vector<vector<int>> board)
{
    int answer = 0;

    int size = board.size();

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            Map[i][j] = board[i][j];

    for(int i=0;i<size;i++)
    {
	    for(int j=0;j<size;j++)
	    {
		    if(Map[i][j]==1)
		    {
			    if(i-1>=0)
			    {
                    if(Map[i-1][j]==0)
						Map[i-1][j] = -1;   
                    if(j-1>=0&&Map[i-1][j-1]==0)
                    {
                        Map[i - 1][j - 1] = -1;
                    }
                    if(j+1<size&&Map[i-1][j+1]==0)
                    {
                        Map[i - 1][j + 1] = -1;
                    }
			    }
                if (j - 1 >= 0&&Map[i][j-1]==0)
                    Map[i][j - 1] = -1;
                if (j + 1 < size&&Map[i][j+1]==0)
                    Map[i][j + 1] = -1;

                if(i+1<size)
                {
                    if(Map[i+1][j]==0)
						Map[i + 1][j] = -1;
                    if (j + 1 < size&&Map[i+1][j+1]==0)
                        Map[i + 1][j + 1] = -1;
                    if (j - 1 >= 0&&Map[i+1][j-1]==0)
                        Map[i + 1][j - 1] = -1;
                }


		    }
	    }
    }

    bool check = false;

    for(int i=0;i<size;i++)
    {
	    for(int j=0;j<size;j++)
	    {
		    if(Map[i][j]==0)
		    {
                check = true;
                answer++;
		    }
	    }
    }

    if (!check)
        return 0;

    return answer;
}

int main()
{
    vector<vector<int>> v = 
    {
    	{{1, 1, 1, 1, 1},
    	{1, 1, 1, 1, 1},
    	{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1}}
    };

    cout << solution(v);

	return 0;
}