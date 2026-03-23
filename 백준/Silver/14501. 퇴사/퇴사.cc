#include <iostream>
#include <vector>
using namespace std;

vector<int> v_time;
vector<int> price;
int n, MAX = -1;

void dfs(int day, int total) {
    // 퇴사날
    if(day >= n + 1) {
        if(total > MAX) {
            MAX = total;
        }
        return;
    }
    
    // 이 상담이 n일 초과가 아니라면 선택
    if(day + v_time[day] <= n + 1) {
        dfs(day + v_time[day], total + price[day]);
    }
    // 이 상담을 선택 안 할 시
    dfs(day + 1, total);
}

int main() {
    cin >> n;

    v_time.resize(n + 1);
    price.resize(n + 1);

    for(int i = 1; i < n + 1; i++) {        
        int t, p;
        cin >> t >> p;

        v_time[i] = t;
        price[i] = p;
    }

    dfs(1, 0);

    cout << MAX;
}
