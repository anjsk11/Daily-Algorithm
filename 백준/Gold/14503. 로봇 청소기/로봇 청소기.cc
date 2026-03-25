#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    int x, y, d;
    cin >> x >> y >> d;

    for(int i  = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cnt = 0;

    while(1) {
        if(grid[x][y] == 0) {
            grid[x][y] = 2;
            cnt++;
        }

        bool is_clean = false;
        for(int i = 0; i < 4; i++) {
            if(grid[x + dx[i]][y + dy[i]] == 0) {
                is_clean = true;
            }
        }

        if(!is_clean) {
            x += dx[(d + 2) % 4];
            y += dy[(d + 2) % 4];
            if(grid[x][y] == 1) {
                break;
            }
        }
        else {
            d = (d + 3) % 4;
            if(grid[x + dx[d]][y + dy[d]] == 0) {
                x += dx[d];
                y += dy[d];
            }
        }
    }

    cout << cnt;
}