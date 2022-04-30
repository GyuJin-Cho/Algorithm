#include <string>
#include <iostream>
#include <map>

using namespace std;


int solution(string dirs) 
{
    int answer = 0;

    pair<int, int> Point;

    Point = make_pair(5, 5);

    map<pair<pair<int, int>, pair<int, int>>, bool> visit;

    for (int i = 0; i < dirs.length(); i++)
    {
        int startx = Point.first;
        int starty = Point.second;
        if (dirs[i] == 'U')
        {
            if (Point.first - 1 < 0)
                continue;

            Point = make_pair(Point.first - 1, Point.second);

        }
        else if (dirs[i] == 'D')
        {
            if (Point.first + 1 > 10)
                continue;

            Point = make_pair(Point.first + 1, Point.second);

        }

        else if (dirs[i] == 'R')
        {
            if (Point.second + 1 > 10)
                continue;

            Point = make_pair(Point.first, Point.second + 1);
       
        }
        else if (dirs[i] == 'L')
        {
            if (Point.second-1 < 0)
                continue;

            Point = make_pair(Point.first, Point.second - 1);

        }

        if (visit[make_pair(make_pair(startx,starty),make_pair(Point.first,Point.second))]==true)
            continue;

        visit[make_pair(make_pair(startx, starty), make_pair(Point.first, Point.second))] = true;
        visit[make_pair(make_pair(Point.first, Point.second), make_pair(startx, starty))] = true;
        answer++;
    }

    return answer;
}

int main()
{
    cout << solution("ULURRDLLU");

    return 0;
}