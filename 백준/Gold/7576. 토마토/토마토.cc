#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // 그리드 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp; 
            if(temp == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int max = 0;

    // bfs
    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
                int nx = currx + dx[i];
                int ny = curry + dy[i];
                //out of bounds or -1
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == -1) {
                    continue;
                }
                // 방문하지 않았다면
                if(dist[nx][ny] == -1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 1;
                    dist[nx][ny] = dist[currx][curry] + 1;
                    max = dist[nx][ny];
                }
        }
    }

    for(auto& row : grid) {
        for(auto& e : row) {
            if(e == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << max;
}
