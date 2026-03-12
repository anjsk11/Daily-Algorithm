#include <iostream>
#include <vector>
using namespace std;

int MAX = -1000000001;
int MIN = 1000000001;
vector<int> v;

void dfs(int plus, int minus, int mult, int div, int ind, int sum) {
    if(ind == v.size()) {
        if(sum > MAX)
            MAX = sum;
        if(sum < MIN)
            MIN = sum;

        return;
    }
    
    if(plus > 0)
        dfs(plus - 1, minus, mult, div, ind + 1, sum + v[ind]);
    if(minus > 0)
        dfs(plus, minus - 1, mult, div, ind + 1, sum - v[ind]);
    if(mult > 0)
        dfs(plus, minus, mult - 1, div, ind + 1, sum * v[ind]);
    if(div > 0)
        dfs(plus, minus, mult, div - 1, ind + 1, sum / v[ind]);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int plus, minus, mult, div;
    cin >> plus >> minus >> mult >> div;
    dfs(plus, minus, mult, div, 1, v[0]);

    cout << MAX << '\n' << MIN;
}