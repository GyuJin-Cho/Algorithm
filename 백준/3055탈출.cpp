#include<iostream>
#include<queue>
using namespace std;

struct info 
{
    int x;
    int y;
};

int R, C;
int ans;
char map[51][51];
queue<info> S;
queue<info> W;
int px[4] = { 1,0,-1,0 };
int py[4] = { 0,1,0,-1 };
bool visited[51][51];

void W_move() {
    int end_cnt = W.size();
    for (int i = 0; i < end_cnt; i++) 
    { 
        int cx = W.front().x;
        int cy = W.front().y;
        W.pop();
        for (int i = 0; i < 4; i++) 
        {
            int nx = cx + px[i];
            int ny = cy + py[i];
            if (ny > R || ny<1 || nx>C || nx < 1) continue;
            if (map[ny][nx] == '.') 
            {
                info n;
                n.x = nx; n.y = ny;
                map[ny][nx] = '*';
                W.push(n);
            }
        }
    }
}

void S_move() {
    bool check = false;
    int time = 0;
    while (!S.empty()) 
    {
        time++;
        W_move();
        int end_d = S.size();
        for (int d = 0; d < end_d; d++)
        {
            int cx = S.front().x;
            int cy = S.front().y;
            S.pop();
            if (map[cy][cx] == 'D') 
            {
                check = true;
                cout << time - 1 << endl;
                break;
            }
            for (int i = 0; i < 4; i++) 
            {
                int nx = cx + px[i];
                int ny = cy + py[i];
                if (map[ny][nx] == '*' || map[ny][nx] == 'X' || map[ny][nx] == 'S') continue;
                if (ny > R || ny<1 || nx>C || nx < 1) continue;
                info n;
                n.x = nx; n.y = ny;
                if (map[ny][nx] == '.') map[ny][nx] = 'S';
                S.push(n);
            }
        }
        if (check == true) break;
    }
    if (!check) cout << "KAKTUS" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int y = 1; y <= R; y++) 
    {
        for (int x = 1; x <= C; x++) 
        {
            cin >> map[y][x];
            if (map[y][x] == 'S')
            {
                info i;
                i.x = x; i.y = y;
                S.push(i);
                visited[y][x] = true;
            }
            if (map[y][x] == 'D')
            {
                info d;
                d.x = x; d.y = y;
            }
            if (map[y][x] == '*') 
            {
                info w;
                w.x = x; w.y = y;
                W.push(w);
            }
        }
    }

    S_move();


}