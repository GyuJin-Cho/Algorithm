#include <string>
#include <vector>
#include <iostream>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	stack<int> s;

	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[j][moves[i] - 1] != 0)
			{
				s.push(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
		if (s.size() >= 2)
		{
			int arr[2];
			for (int j = 0; j < 2; j++)
			{
				arr[j] = s.top();
				s.pop();
			}
			if (arr[1] == arr[0])
			{
				answer += 2;
			}
			else
			{
				for (int j = 1; j >= 0; j--)
				{
					s.push(arr[j]);
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> b=
	{
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1}
	};
	vector<int> m = { 1,5,3,5,1,2,1,4 };
	cout << solution(b, m);
	return 0;
}