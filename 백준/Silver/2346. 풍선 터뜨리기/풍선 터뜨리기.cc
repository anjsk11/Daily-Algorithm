#include <iostream>
#include <deque>
using namespace std;

struct Balloon{
    int num;
    int paper;
};

int main() {
    int n;
    cin >> n;

    deque<Balloon> balloons;
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        Balloon b;
        balloons.push_back({i, temp});
    }

    while(!balloons.empty()) {
        Balloon balloon = balloons.front();
        cout << balloon.num << ' ';
        balloons.pop_front();

        if(balloons.empty())
            break;

        int paper = balloon.paper;
        if(paper > 0) {
            for(int j = 0; j < paper - 1; j++) {
                balloons.push_back(balloons.front());
                balloons.pop_front();

            }
        }
        else {
            paper *= -1;
            for(int j = 0; j < paper; j++) {
                balloons.push_front(balloons.back());
                balloons.pop_back();

            }
        }
    }
}