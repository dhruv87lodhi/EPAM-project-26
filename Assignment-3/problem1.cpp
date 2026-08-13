// problem 1 - scholarship distribution

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B;
    cin >> N >> B;

    vector<long long> vec(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    for(int i = 0; i<N; i++) {
        B -= vec[i];
        if(B < 0) break;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}