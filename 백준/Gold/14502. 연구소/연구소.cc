#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, m;
int min_virus = 100;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    visited.assign(n, vector<bool>(m, false));
    int cnt = 0;
    queue<pair<int, int>> q;
    // 처음 바이러스 위치 큐에
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                cnt++;
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && grid[nx][ny] == 0 ) {
                cnt++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    if(cnt < min_virus) {
        min_virus = cnt;
    }
    
}

void build_wall(int cnt) {
    // 벽 세 개 완성
    if(cnt == 3) {
        // bfs 후 안전 영역 최댓값 업데이트
        bfs();
        return;
    }

    // 남은 그리드에서 벽 하나 더 세우기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 0) {
                grid[i][j] = 1;
                build_wall(cnt + 1);
                // 복구
                grid[i][j] = 0;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    int cnt_wall = 0;

    // 그리드 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp;
            if(grid[i][j] == 1) {
                cnt_wall++;
            }
        }
    }

    build_wall(0);
    cout << n * m - (cnt_wall + 3) - min_virus;
}