#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for(int i=0;i<arr.size();i++)
    {
	    if(arr[i]%2==0&&arr[i]>=50)
	    {
            arr[i] /= 2;
	    }
        else if(arr[i]%2==1&&arr[i]<50)
        {
            arr[i] *= 2;
        }
    }

    return arr;
}

int main()
{
    vector<int> v = { 1,2,3,100,99,98 };
    vector<int> ans = solution(v);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}