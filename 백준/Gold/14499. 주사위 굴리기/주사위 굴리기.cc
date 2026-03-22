#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }

    vector<int> dice(6, 0);
    int dx[5] = {0, 0, 0, -1, 1};
    int dy[5] = {0, 1, -1, 0, 0};

    for(int i = 0; i < k; i++) {
        int dir;
        cin >> dir;

        int tempx = x + dx[dir];
        int tempy = y + dy[dir];
        if(tempx < 0 || tempx >= n || tempy < 0 || tempy >= m) {
            continue;
        }
        else {
            x = tempx;
            y = tempy;
        }

        vector<int> ndice = dice;
        // 굴리기
        switch(dir) {
            case 1:
                ndice[1] = dice[5];
                ndice[3] = dice[4];
                ndice[4] = dice[1];
                ndice[5] = dice[3];
                break;
            case 2:
                ndice[1] = dice[4];
                ndice[3] = dice[5];
                ndice[4] = dice[3];
                ndice[5] = dice[1];
                break;
            case 3:
                ndice[0] = dice[3];
                ndice[1] = dice[0];
                ndice[2] = dice[1];
                ndice[3] = dice[2];
                break;
            case 4:
                ndice[0] = dice[1];
                ndice[1] = dice[2];
                ndice[2] = dice[3];
                ndice[3] = dice[0];
                break;            
        }
        dice = ndice;

        if(grid[x][y] == 0) {
            grid[x][y] = dice[1];
        }
        else {
            dice[1] = grid[x][y];
            grid[x][y] = 0;
        }

        cout << dice[3] << '\n';
    }
}