#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  3e5 + 10;
int a[N], dp[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fill(dp + 1, dp + 1 + n, INF);
    for (int i = 0; i < n; i++) {
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0 && dp[j] != INF && dp[i / j] != INF) {
                dp[i] = min(dp[i], dp[i / j] + dp[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == INF) cout << "-1 ";
        else cout << dp[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}