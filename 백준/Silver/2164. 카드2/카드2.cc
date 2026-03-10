#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> cards;
    for(int i = 1; i <= n; i++) {
        cards.push(i);
    }
    
    int temp = 1;
    while(cards.size() > 1) {
        cards.pop();
        temp = cards.front();
        cards.pop();
        cards.push(temp);
    }

    cout << temp;
}