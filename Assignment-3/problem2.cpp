// problem 2 - maximum learning points

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i]; 
    }

    vector<int> dp(N);
    dp[N-1] = vec[N-1];
    dp[N-2] = vec[N-2];

    for(int i = N-3; i >= 0; i--) {
        dp[i] = max(dp[i+1], vec[i] + dp[i+2]);
    }

    cout << dp[0] << endl;

    return 0;
}