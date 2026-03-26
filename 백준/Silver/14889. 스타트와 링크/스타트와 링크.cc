#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> skill;
unordered_set<int> team1;
unordered_set<int> team2;
int n;
int MIN = 1e9;
int total = 0;

int get_skill(unordered_set<int>& team) {
    int sum = 0;

    for(auto& mem1 : team) {
        for(auto& mem2 : team) {
            sum += skill[mem1][mem2];
        }
    }

    return sum;
}

void dfs(int start, int cnt) {
    if(cnt == n / 2) {
        int skill1 = get_skill(team1);
        int skill2 = get_skill(team2);
        int diff = skill1 > skill2 ? skill1 - skill2 : skill2 - skill1;
        if(diff < MIN) {
            MIN = diff;
        }
        return;
    }

    for(int i = start; i < n; i++) {
        team1.insert(i);
        team2.erase(i);
        dfs(i + 1, cnt + 1);
        team1.erase(i);
        team2.insert(i);
    }
}

int main() {
    cin >> n;
    skill.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        team2.insert(i);

        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            total += temp;
            skill[i][j] = temp;
        }
    }

    dfs(0, 0);
    cout << MIN;
}