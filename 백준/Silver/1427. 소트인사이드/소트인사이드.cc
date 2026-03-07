#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    cout << s;
}