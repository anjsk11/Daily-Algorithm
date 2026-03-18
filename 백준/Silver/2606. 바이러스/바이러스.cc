#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> infected;

void dfs(int start) {
    infected[start] = true;

    for(auto next : graph[start]) {
        if(!infected[next])
            dfs(next);
    }
}

int main() {
    int n;
    cin >> n;
    graph.resize(n + 1);
    infected.assign(n + 1, false);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << count(infected.begin(), infected.end(), true) - 1;
}