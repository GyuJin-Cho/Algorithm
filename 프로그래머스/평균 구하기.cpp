#include <string>
#include <vector>
#include<iostream>

using namespace std;

double solution(vector<int> arr)
{
    double answer = 0;
    double sum = 0;
    int size=arr.size();
    for(int i=0; i< arr.size();i++)
    {
        sum += arr[i];
    }
    
    answer = sum / arr.size();
    return answer;
}

int main()
{
    vector<int> arr={1,2,3,4};
    cout << solution(arr) << endl;
    return 0;
}