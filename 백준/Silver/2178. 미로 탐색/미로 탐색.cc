#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            maze[i][j] = s[j] - '0'; 
        }
    }

    // bfs
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    q.push({0, 0});
    maze[0][0] = 0;
    dist[0][0] = 1;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0 , -1, 1};

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // n, m 도착
        if(x == n - 1 && y == m - 1) 
        break; 
    

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // out of bounds
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            
            if(maze[nx][ny] == 1) {
                q.push({nx, ny});
                maze[nx][ny] = 0;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    cout << dist[n - 1][m - 1];
}