#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores)
{
    string answer = "";
    int x=scores.size();
    int y = scores[0].size();
    int xself = 0;
    int yself = 0;
    int count = x - 1;
    int max=-1;
    int min = 1000000;
    for(int i=0;i<x;i++)
    {
        int maxcheck = 0;
        int mincheck = 0;
        int sum = 0;
	    for(int j=0;j<y;j++)
	    {
		    if(i==xself&&j==yself)
		    {
                max = scores[j][i];
                min = scores[j][i];
                for(int z=j;z>=0;z--)
                {
                    if (max > scores[z][i])
                    {
                        maxcheck++;
                    }
                    else if (min < scores[z][i])
                    {
                        mincheck++;
                    }
                }
                continue;
		    }
            else
            {
                if(max>scores[j][i])
                {
                    maxcheck++;
                }
                else if(min<scores[j][i])
                {
                    mincheck++;
                }
                sum += scores[j][i];
            }
	    }
        double div;
        if(maxcheck==count)
        {
            div = sum / count;
        }
        else if(mincheck==count)
        {
            div = sum / count;
        }
        else
        {
            sum += max;
            div = sum/(count + 1);
        }
        if (div >= 90)
            answer += "A";
        else if(div >=80&& div<90)
            answer += "B";
        else if (div >= 70 && div < 80)
            answer += "C";
        else if (div >= 50 && div < 70)
            answer += "D";
        else if (div <50)
            answer += "F";
        xself++;
        yself++;
        max = -1;
        min = 10000000;
    }
    return answer;
}

int main()
{
    vector<vector<int>> scores = { {100, 90, 98, 88, 65},{50, 45, 99, 85, 77}
        ,{47, 88, 95, 80, 67},{61, 57, 100, 80, 65},{24, 90, 94, 75, 65} };
    cout << solution(scores);
    return 0;
}