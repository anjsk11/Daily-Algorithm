#include <iostream>
#include <algorithm>
using namespace std;

int cache[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++) {
        int temp1 = 1000000, temp2 = 1000000, temp3 = 1000000;
        if(i % 3 == 0) 
            temp1 = cache[i / 3];
        if(i % 2 == 0) 
            temp2 = cache[i / 2];
        temp3 = cache[i - 1];

        cache[i] = min({temp1, temp2, temp3}) + 1;
    }

    cout << cache[n];
}