
#include<iostream>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int map[101][101];
bool ch[101][101];
int answer=0;
int w,h;
void chInit()
{
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            ch[i][j] = false;
}

void DFS(int Y,int X)
{
    for(int i=0;i<8;i++)
    {
        int Ny = dy[i]+Y;
        int Nx = dx[i]+X;
        if(Ny>=0&&Nx>=0&&Ny<h&&Nx<w)
        {
            if(!ch[Ny][Nx]&&map[Ny][Nx])
            {
                ch[Ny][Nx] = true;
                DFS(Ny,Nx);
            }
        }
            
    }
}

int main()
{
    
    while(1)
    {
        cin>>w>>h;
        answer=0;
        if(w==0&&h==0)
            break;
        chInit();
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>map[i][j];
            }
        }
        
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(map[i][j]==1&&!ch[i][j])
                {
                    ch[i][j] = true;
                    DFS(i,j);
                    answer++;
                }
            }
        }
        cout<<answer<<'\n';
    }
    
    return 0;
}
