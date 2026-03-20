#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;

    // 사과면 2, 뱀이면 1, 나머진 0
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }
    board[1][1] = 1;

    int l;
    cin >> l;

    queue<pair<int, char>> inputs;
    for(int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        inputs.push({x, c});
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ind = 1;
    auto [input_time, input] = inputs.front();
    inputs.pop();

    int headx = 1, heady = 1;
    queue<pair<int, int>> snake;
    snake.push({1, 1});

    int seconds = 0;
    while(1) {
        // input이 있으면 방향수정
        if(seconds == input_time) {
            if(input == 'L') {
                ind = (ind +3) % 4;
            }
            else {
                ind = (ind + 1) % 4;
            }

            if(!inputs.empty()) {
                input_time = inputs.front().first;
                input = inputs.front().second;
                inputs.pop();
            }    
        }
        
        // 이동
        headx += dx[ind];
        heady += dy[ind];
        seconds++;
        
        // 벽으로 이동 체크
        if(headx < 1 || headx > n || heady < 1 || heady > n) {
            break;
        }

        bool eaten = false;
        switch(board[headx][heady]) {
            // 뱀 먹음
            case 1:
                eaten  = true;
                break;
            // 사과 먹음
            case 2:
                board[headx][heady] = 1;
                break;
            default:
                board[headx][heady] = 1;
                auto [tailx, taily] = snake.front();
                board[tailx][taily] = 0;
                snake.pop();
                break;
        }

        if(eaten) {
            break;
        }

        snake.push({headx, heady});
    }

    cout << seconds;
}