#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    int cnt = 0;
    vector<int> beforarr(arr.size());
    while(cnt!=arr.size())
    {
        cnt = 0;
        beforarr = arr;
        for(int i=0;i<arr.size();i++)
        {
	        if(arr[i]%2==0&&arr[i]>=50)
	        {
                arr[i] /= 2;
	        }
            else if(arr[i]%2!=0&&arr[i]<50)
            {
                arr[i] = arr[i] * 2 + 1;
            }
            if (arr[i] == beforarr[i])
                cnt++;
        }
        answer++;
    }
    return answer - 1;
}

int main()
{
    vector<int> arr = { 1, 2, 3, 100, 99, 98 };
    int result = solution(arr);
    cout << result << endl;
    return 0;
}