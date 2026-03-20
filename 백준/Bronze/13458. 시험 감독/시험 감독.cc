#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rooms;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        rooms.push_back(a);
    }

    int b, c;
    cin >> b >> c;

    long long total = n;
    for(auto room : rooms) {
        room -= b;
        if(room <= 0)
            continue;
        
        total += (room + c - 1) / c;
    }

    cout << total;
}