#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> order)
{
    int answer = 0;
    unordered_map<string,int> m;
    m["iceamericano"] = 4500;
    m["americanoice"] = 4500;
    m["hotamericano"] = 4500;
    m["americanohot"] = 4500;
    m["icecafelatte"] = 5000;
    m["cafelatteice"] = 5000;
    m["hotcafelatte"] = 5000;
    m["cafelattehot"] = 5000;
    m["americano"] = 4500;
    m["cafelatte"] = 5000;
    m["anything"] = 4500;
    
    for(string i : order)
    {
        answer+= m[i];
    }
    
    
    return answer;
}

int main()
{
    vector<string> o ={"cafelatte", "americanoice", "hotcafelatte", "anything"};
    cout<<solution(o);
    
    return 0;
}
