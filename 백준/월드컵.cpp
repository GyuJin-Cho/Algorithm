#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int team1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int team2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

int a[4][6][3];
int result[6][3];
int ans[4];

void DFS(int Depth)
{
    if (Depth == 15)
    {
        for (int t = 0; t < 4; t++) 
        {
            if (ans[t] == 1) 
                continue;

            bool flag = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 3; j++) 
                {
                    if (a[t][i][j] != result[i][j]) 
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) 
                    break;
            }

            if (flag) 
            {
                ans[t] = 1;
            }
        }

        return;
    }

    int t1 = team1[Depth];
    int t2 = team2[Depth];

    // t1 win, t2 lose
    result[t1][0]++;
    result[t2][2]++;
    DFS(Depth + 1);
    result[t1][0]--;
    result[t2][2]--;

    // t1 draw, t2 draw
    result[t1][1]++;
    result[t2][1]++;
    DFS(Depth + 1);
    result[t1][1]--;
    result[t2][1]--;

    // t1 lose, t2 win
    result[t1][2]++;
    result[t2][0]++;
    DFS(Depth + 1);
    result[t1][2]--;
    result[t2][0]--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int t=0;t<4;t++)
	{
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin >> a[t][i][j];
			}
		}
	}
	DFS(0);
	for(int i=0;i<4;i++)
	{
		cout << ans[i] << ' ';
	}
    cout << "\n";
	return 0;
}