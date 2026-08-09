// problem 1 - Tree of trusted servers

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<long long> key(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> key[i];
    }

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> xorPath(N + 1);
    vector<bool> vis(N + 1, false);

    queue<int> q;

    xorPath[1] = key[1];
    vis[1] = true;
    q.push(1);

    int ans = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (xorPath[u] >= K) {
            ans++;
        }

        for (int v : adj[u]) {

            if (vis[v])
                continue;

            vis[v] = true;
            xorPath[v] = xorPath[u] ^ key[v];

            q.push(v);
        }
    }

    cout << ans << '\n';

    return 0;
}