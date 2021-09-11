#include <string>
#include <vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

bool cmp(tuple<int,string,int> t1 , tuple<int,string,int> t2)
{

    if (get<0>(t1) > get<0>(t2))
        return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    map<string, int> m;
    for(int i=0;i<genres.size();i++)
    {
	    if(m.find(genres[i])==m.end())
	    {
            m.insert(make_pair(genres[i], plays[i]));
	    }
        else if(m.find(genres[i])!=m.end())
        {
            m[genres[i]] += plays[i];
        }
    }
    map<int, string,greater<int>> sortMap;
    for(auto iter = m.begin(); iter!=m.end();iter++)
    {
        sortMap.insert({ iter->second,iter->first });
    }
    vector<tuple<int,string,int>> answerMap;
    for(int i=0;i<plays.size();i++)
    {
        answerMap.push_back(make_tuple(plays[i],genres[i],i));
    }
    sort(answerMap.begin(), answerMap.end(), cmp);
    vector<int> v;
    for(auto iter = sortMap.begin();iter!=sortMap.end();iter++)
    {
        int count = 0;
	    for(int i=0;i<answerMap.size();i++)
	    {
            if (count == 2)
                break;
            if(get<1>(answerMap[i])==iter->second)
            {
                count++;
                answer.push_back(get<2>(answerMap[i]));
            }
	    }
    }
    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" ,"pop"};
    vector<int> plays = { 500, 2500, 150, 800, 2500 ,2500};
    vector<int> v = solution(genres, plays);
    return 0;
}