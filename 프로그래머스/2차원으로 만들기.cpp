#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> temp;
    for (int i = 0; i < num_list.size(); i++)
    {
        temp.push_back(num_list[i]);
        if ((i + 1) % n == 0)
        {
            answer.push_back(temp);
            temp.clear();
        }

    }

    return answer;
}

int main()
{
    vector<int> numlist = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<vector<int>> a = solution(numlist, 2);

    for(int i=0;i<a.size();i++)
    {
	    for(int j=0;j<a[i].size();j++)
	    {
            cout << a[i][j] << " ";
	    }
        cout << endl;
    }

    return 0;
}