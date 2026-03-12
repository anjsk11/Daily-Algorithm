#include <iostream>
using namespace std;

int cnt_hanoi(int n)
{
    if(n == 1)
        return 1;

    return 2 * cnt_hanoi(n-1) + 1;
}

void hanoi(int disk, int spole, int epole) {
    if(disk == 1){
        cout << spole << ' ' << epole << '\n';
        return;
    }
    
    int temp_pole = 6 - spole - epole;
    hanoi(disk - 1, spole, temp_pole);

    cout << spole << ' ' << epole << '\n';

    hanoi(disk - 1, temp_pole, epole);
}

int main() {
    int n;
    cin >> n;

    cout << cnt_hanoi(n) << '\n';
    hanoi(n, 1, 3);
}