#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    
    for (int i = 0; i < answer.size(); i++)
    {
        vector<int> sum;
        for (int j = 0; j < answer[i].size(); j++)
        {
            sum.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(sum);
    }
    return answer;
}

int main()
{
    vector<vector<int>> arr1 = { {1},{2} };
    vector < vector<int>> arr2 = { {3},{4} };
    vector<vector<int>> v = solution(arr1, arr2);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout << v[i][j];
        }
    }
    return 0;
}