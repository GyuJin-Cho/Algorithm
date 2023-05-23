#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx)
{

    for(int i=idx;i<arr.size();i++)
    {
        if(arr[i]==1)
        {
            return i;
            break;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = { 0,0,0,1 };
    cout << solution(v, 1);

    return 0;
}
