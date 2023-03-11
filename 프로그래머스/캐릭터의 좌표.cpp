#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> answer;

    int MaxX = (board[0] - 1) / 2;
    int MaxY = (board[1] - 1) / 2;
    int MinX = -(board[0] - 1) / 2;
    int MinY = -(board[1] - 1) / 2;

    int X = 0, Y = 0;

    for(int i=0;i<keyinput.size();i++)
    {
	    if(keyinput[i]=="up")
	    {
            if (Y + 1 > MaxY)
                continue;
            Y += 1;
	    }
        else if(keyinput[i] == "down")
        {
	        if(Y - 1 < MinY)
                continue;
            Y -= 1;
        }
        else if(keyinput[i] == "left")
        {
	        if(X-1<MinX)
				continue;
            X -= 1;
        }
        else if(keyinput[i] == "right")
        {
	        if(X+1>MaxX)
                continue;
            X += 1;
        }
    }
    answer.push_back(X);
    answer.push_back(Y);
    return answer;
}

int main()
{
    vector<string> key={ "down", "down", "down", "down", "down" };
    vector<int> board = { 7,9 };

    vector<int> a = solution(key, board);

    for (auto i : a)
        cout << i << " ";

    return 0;
}