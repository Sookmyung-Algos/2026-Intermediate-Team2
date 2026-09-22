// 정올 1462. 보물섬 
#if 0
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node
{
    int x;
    int y;
    int dist;
}N;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; ++i)
    {
        cin >> grid[i];
    }

    int maxT = 0;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (grid[i][j] == 'L')
            {
                vector<vector<bool>> visited(R, vector<bool>(C, false));
                queue<N> q;

                q.push({ i, j, 0 });
                visited[i][j] = true;

                int maxV = 0;

                while (!q.empty())
                {
                    N curr = q.front();
                    q.pop();

                    if (curr.dist > maxV)
                    {
                        maxV = curr.dist;
                    }

                    for (int d = 0; d < 4; ++d)
                    {
                        int nx = curr.x + dx[d];
                        int ny = curr.y + dy[d];

                        if (nx >= 0 && nx < R && ny >= 0 && ny < C)
                        {
                            if (grid[nx][ny] == 'L' && !visited[nx][ny])
                            {
                                visited[nx][ny] = true;
                                q.push({ nx, ny, curr.dist + 1 });
                            }
                        }
                    }
                }

                if (maxV > maxT)
                {
                    maxT = maxV;
                }
            }
        }
    }

    cout << maxT << "\n";

    return 0;
}
#endif