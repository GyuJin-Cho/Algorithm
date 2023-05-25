#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<string> strArr)
{
    int answer = -217400000;
    
    map<int,int> m;
    
    for(int i=0;i<strArr.size();i++)
    {
        m[strArr[i].size()]++;
    }
    
    for(auto i : m)
    {
        answer = max(answer,i.second);
    }
    
    return answer;
}

int main()
{
    
    vector<string> s = {"a","bc","d","efg","hi"};
    cout<<solution(s);
    
    return 0;
}
