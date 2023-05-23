#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
    vector<int> answer;

    switch (n)
    {
    case 1:
	    {
			for(int i=0;i<=slicer[1];i++)
			{
                answer.push_back(num_list[i]);
			}
			break;
	    }
    case 2:
	    {
            for(int i=slicer[0];i<num_list.size();i++)
            {
                answer.push_back(num_list[i]);
            }
            break;
	    }
    case 3:
	    {
            for(int i = slicer[0];i<=slicer[1];i++)
            {
                answer.push_back(num_list[i]);
            }
			break;
	    }
    case 4:
	    {
            for (int i = slicer[0]; i <= slicer[1]; i=i+slicer[2])
            {
                answer.push_back(num_list[i]);
            }
			break;
	    }
    }

    return answer;
}

int main()
{
    vector<int> slice = { 1, 5, 2 };
    vector<int> numlist = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> ans = solution(4, slice, numlist);
    for (auto i : ans)
        cout << i << ' ';

    return 0;
}