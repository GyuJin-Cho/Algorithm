#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>

using namespace std;
int a[10][10];
int d[10][10];
int p[10][10];
vector<int> tree[10][10];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> a[i][j];
            d[i][j] = 5; // ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.
        }
    }
    while (m--)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x - 1][y - 1].push_back(age);
    }
    while (l--) 
    {
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                vector<int> temp;
                sort(tree[i][j].begin(), tree[i][j].end()); // �ϳ��� ĭ�� ���� ���� ������ �ִٸ�, ���̰� � �������� ����� �Դ´�.
                int dead = 0;
                for (int x : tree[i][j]) 
                {
                    if (x <= d[i][j]) 
                    {
                        d[i][j] -= x; // ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.
                        temp.push_back(x + 1);
                        if ((x + 1) % 5 == 0)
                        { // �����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�,
                            for (int k = 0; k < 8; k++) 
                            {
                                int nx = i + dx[k];
                                int ny = j + dy[k];
                                if (0 <= nx && nx < n && 0 <= ny && ny < n) { // ���� ���� ����� ĭ���� ������ ������ �ʴ´�.
                                    p[nx][ny] += 1; // ������ 8���� ĭ�� ���̰� 1�� ������ �����.
                                }
                            }
                        }
                    }
                    else 
                    { // ����, ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����� ���� ���ϰ� ��� �״´�.
                        dead += x / 2; // ������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�.
                    }
                }
                tree[i][j] = temp;
                d[i][j] += dead;
                d[i][j] += a[i][j]; // �� ĭ�� �߰��Ǵ� ����� ���� A[r][c]�̰�, �Է����� �־�����.
            }
        }
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                for (int k = 0; k < p[i][j]; k++) 
                {
                    tree[i][j].push_back(1); // ������ 8���� ĭ�� ���̰� 1�� ������ �����.
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            ans += (int)tree[i][j].size();
        }
    }
    cout << ans << '\n';
    return 0;
}
