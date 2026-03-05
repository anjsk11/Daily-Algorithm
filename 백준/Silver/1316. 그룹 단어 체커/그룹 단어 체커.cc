#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

bool is_group(string s) {
    unordered_set<char> set;
    for(char c: s) {
        if(set.count(c))
            return false;
        else
            set.insert(c);
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    string s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> s;
        s.erase(unique(s.begin(), s.end()), s.end());
        if(is_group(s))
            cnt++;
    }

    cout << cnt;
}