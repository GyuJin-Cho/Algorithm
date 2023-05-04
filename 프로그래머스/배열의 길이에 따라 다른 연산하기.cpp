#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n)
{
    if(arr.size()%2==1)
    {
        for (int i = 0; i < arr.size(); i = i + 2)
        {
            arr[i] += n;
        }
    }
    else
    {
        for (int i = 1; i < arr.size(); i = i + 2)
        {
            arr[i] += n;
        }
    }

    return arr;
}

int main()
{
    vector<int> v = { 444, 555, 666, 777 };
    vector<int> ans = solution(v, 100);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}