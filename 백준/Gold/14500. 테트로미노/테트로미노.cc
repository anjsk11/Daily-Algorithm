#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, m;
int MAX = -1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int cnt, int total, int x, int y) {
    // 4개 다 채웠을 때
    if(cnt == 4) {
        if(total > MAX) {
            MAX = total;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(cnt + 1, total + grid[nx][ny], nx, ny);
            visited[nx][ny] = false;
        }
    }
}

void check_T(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int total = grid[x][y];
        for(int j = 0; j < 4; j++) {
            // 4방향 중 하나 스킵
            if(j == i) {
                continue;
            }

            int nx = x + dx[j];
            int ny = y + dy[j];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                total += grid[nx][ny];
            }
            else {
                break;
            }
        }
        if(total > MAX) {
            MAX = total;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    grid.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));  

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(1, grid[i][j], i, j);
            check_T(i, j);
            visited[i][j] = false;
        }
    }

    cout << MAX;
}