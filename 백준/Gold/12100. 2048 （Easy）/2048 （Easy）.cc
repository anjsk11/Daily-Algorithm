#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MAX = -1, n;

void move(vector<vector<int>>& board) {
    queue<int> q;
    for(auto& row : board) {
        for(auto& e : row) {
            if(e != 0) {
                q.push(e);
                e = 0;
            }
            else {
                continue;
            }
        }

        int ind = 0;
        while(!q.empty()) {           
            int temp = q.front();
            q.pop();

            if(!q.empty()) {
                if(temp == q.front()) {
                    q.pop();
                    temp *= 2;
                }
            }

            row[ind] = temp;
            ind++;
        }
    }
}

void rotate(vector<vector<int>>& board) {
    vector<vector<int>> temp = board;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[n - 1 - j][i] = temp[i][j];
        }
    }
}

void dfs(int cnt, vector<vector<int>> board) {
    // 5번째
    if(cnt == 5) {
        for(auto& row : board) {
            for(auto& e : row) {
                if(e > MAX) {
                    MAX = e;
                }
            }
        }
        return;
    }
    
    move(board);
    cnt++;

    // 보드 회전을 시켜 4방향 대체
    dfs(cnt, board);
    for(int i = 0; i < 3; i++) {
        rotate(board);
        dfs(cnt, board);
    }
}

int main() {
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            board[i][j] = temp; 
        }
    }

    dfs(0, board);
    for(int i = 0; i < 3; i++) {
        rotate(board);
        dfs(0, board);
    }

    cout << MAX;
}