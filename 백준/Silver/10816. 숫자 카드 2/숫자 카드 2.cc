#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int num;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
    }

    int m;
    cin >> m;

    int target;
    for(int i = 0; i < m; i++) {
        cin >> target;
        cout << mp[target] << ' ';
    }
}
