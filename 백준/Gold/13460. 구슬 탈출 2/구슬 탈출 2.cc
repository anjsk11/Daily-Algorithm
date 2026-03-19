#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> board;
vector<int> ans;
int dxa[4] = {-1, 1, 0, 0};
int dya[4] = {0, 0, -1, 1};

// 백트래킹
void dfs(int curr, int redx, int redy, int bluex, int bluey, int dx, int dy) {
    // 11번째면 빠져나감
    if(curr > 10)
        return;

    int nredx = redx, nredy = redy;
    int nbluex = bluex, nbluey = bluey;

    int rdist = 0, bdist = 0;


    // 파란 구슬 이동
    while(board[nbluex + dx][nbluey + dy] != '#') {
        bdist++;
        nbluex = nbluex + dx;
        nbluey = nbluey + dy;
        // 파란 구슬이 구멍에
        if(board[nbluex][nbluey] == 'O') {
            return;
        }
    }    

    // 빨간 구슬 이동
    while(board[nredx + dx][nredy + dy] != '#') {
        rdist++;
        nredx = nredx + dx;
        nredy = nredy + dy;
        // 빨간 구슬이 구멍에
        if(board[nredx][nredy] == 'O') {
            ans.push_back(curr);
            return;
        }
    }

    // 구슬이 부딪혀 같은 위치에 있으면 수정
    if(nredx == nbluex && nredy == nbluey) {
        if(rdist > bdist) {
            nredx -= dx;
            nredy -= dy;
        }
        else {
            nbluex -= dx;
            nbluey -= dy;
        }
    }

    // 두 구슬 모두 단 한 칸도 움직이지 않았다면 그대로 리턴
    if(nredx == redx && nredy == redy && nbluex == bluex && nbluey == bluey) {
        return; 
    }

    // 4 방향에 대해 다시 dfs
    for(int i = 0; i < 4; i++) {
        dfs(curr + 1, nredx, nredy, nbluex, nbluey, dxa[i], dya[i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    board.resize(n, vector<char>(m, '.'));

    pair<int, int> blue, red;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'B')
                blue = {i, j};
            else if(s[j] == 'R')
                red = {i, j};
            
            if(s[j] == '#' || s[j] == 'O')
                board[i][j] = s[j];
            else
                board[i][j] = '.';
        }
    }

    for(int i = 0; i < 4; i++) {
        dfs(1, red.first, red.second, blue.first, blue.second, dxa[i], dya[i]);
    }

    if(ans.empty())
        cout << -1;
    else 
        cout << *min_element(ans.begin(), ans.end());
}