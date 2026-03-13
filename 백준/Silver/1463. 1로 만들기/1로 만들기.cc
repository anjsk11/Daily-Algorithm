#include <iostream>
using namespace std;

int cache[1000000];

int getmin(int n) {
    int min = 10000000;
    int temp;

    if(n == 1) 
        return 0;
    else if(cache[n] != 0)
        return cache[n];

    if(n % 3 == 0) {
        temp = getmin(n / 3);
        if(temp < min)
            min = temp;
    }

    if(n % 2 == 0) {
        temp = getmin(n / 2);
        if(temp < min)
            min = temp;
    }

    temp = getmin(n - 1);
    if(temp < min)
        min = temp;

    cache[n] = min + 1;
    return min + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << getmin(n);
}