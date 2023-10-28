#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int arr[] = { 3,2,1,0,1,2,3 };

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    unordered_map<char, int> um;
    for(int i=0;i<choices.size();i++)
    {
	    if(choices[i]==4)
            continue;
        else if(choices[i]>4)
        {
            um[survey[i][1]] += arr[choices[i]-1];
        }
        else if(choices[i]<4)
        {
            um[survey[i][0]] += arr[choices[i]-1];
        }
    }

    answer += um['R'] >= um['T'] ? "R" : "T";
    answer += um['C'] >= um['F'] ? "C" : "F";
    answer += um['J'] >= um['M'] ? "J" : "M";
    answer += um['A'] >= um['N'] ? "A" : "N";

    return answer;
}

int main()
{
    vector<string> sur = { "TR", "RT", "TR" };
    vector<int> cho = { 7, 1, 3 };
    cout << solution(sur, cho);

    return 0;
}