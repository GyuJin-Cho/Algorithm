#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    vector<int> answer;
    for(int i=0;i<arr.size();i++)
    {
	    for(int j=0;j<delete_list.size();j++)
	    {
		    if(arr[i]==delete_list[j])
		    {
                arr[i] = 0;
		    }
	    }
    }

    for(int i=0;i<arr.size();i++)
    {
	    if(arr[i] ==0 )
	    {
		    continue;
	    }
        answer.push_back(arr[i]);
    }

    return answer;
}

int main()
{
    vector<int> arr, arr1;
    arr1 = { 94, 777, 104, 1000, 1, 12 };
    arr = { 293, 1000, 395, 678, 94 };
    vector<int> v = solution(arr, arr1);
    for (auto i : v)
    {
        cout << i << ' ';
    }

    return 0;
}