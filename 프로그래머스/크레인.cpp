#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
	int answer = 0;
	int comp[2];
	stack<int> S;
	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board[moves[i]-1].size(); j++)
		{
			if (board[j][moves[i] - 1] <= 0)
				continue;
			else
			{
				S.push(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
		if (S.size() >= 2)
		{
			for (int i = 0; i < 2; i++)
			{
				comp[i] = S.top();
				S.pop();
			}
			if (comp[1] == comp[0])
			{
				answer++;
			}
			else
			{
				for (int i = 1; i >= 0; i--)
				{
					S.push(comp[i]);
				}
			}
		}
	}


	return answer*2;
}

int main()
{
	vector<vector<int>> board =
	{
		{ 0,0,0,0,0 },
		{ 0,0,1,0,3 },
		{ 0,2,5,0,1 },
		{ 4,2,4,4,2 },
		{ 3,5,1,3,1 }
	};

	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);
	system("Pause");
	return 0;
}