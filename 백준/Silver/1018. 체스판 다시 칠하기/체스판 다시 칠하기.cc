#include <iostream>
#include <vector>
using namespace std;

int getmin(vector<vector<char>> &v, int x, int y) {
    int cnt1 = 0, cnt2 = 0;
    
    for(int i = x; i < x + 8; i++) {
        for(int j = y; j < y + 8; j++) {
            if((i + j) % 2 == 0) {
                v[i][j] == 'W' ? cnt2++ : cnt1++;
            } 
            else {
                v[i][j] == 'W' ? cnt1++ : cnt2++;
            }
        }
    }

    return (cnt1 < cnt2) ? cnt1 : cnt2;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m, '\0'));

    char in;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> in;
            v[i][j] = in;
        }
    }

    int min = 9999, temp;
    for(int i = 0; i < n - 7; i++) {
        for(int j = 0; j < m - 7; j++) {
            temp = getmin(v, i, j);
            if(temp < min)
                min = temp;
        }
    }

    cout << min;
}