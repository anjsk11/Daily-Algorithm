#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> grid;
int n, cnt;
vector<int> cntv;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    grid[x][y] = 0;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // out of bounds
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        
        if(grid[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    grid.assign(n, vector<int>(n, 0));

    // 맵 생성
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                cnt = 0;
                dfs(i, j);
                cntv.push_back(cnt);
            }
        }
    }

    sort(cntv.begin(), cntv.end());

    cout << cntv.size() << '\n';
    for(auto ans : cntv)
        cout << ans << '\n';
}