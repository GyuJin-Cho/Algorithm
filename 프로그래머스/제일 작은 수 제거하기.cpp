#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int Min;
    vector<int> board = arr;
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }

    else
    {
        sort(arr.begin(), arr.end());
        Min = arr[0];
        int size = board.size();
        for(int i=0;i<size;i++)
        {
	        if(board[i]==Min)
	        {
		        continue;
	        }
            else
            {
                answer.push_back(board[i]);
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> arr = { 4,3,2,1 };
    vector<int> a = solution(arr);
    for(auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}