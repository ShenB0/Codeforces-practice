#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
ll C(ll n, ll m) {
    if (m > n - m) m = n - m;
    ll res = 1;
    for (int i = 1; i <= m; i++) {
        res = res * (n - m + i) / i;
    }
    return res;
}
void solve(){
    int n, k;
    cin >> n >> k;
    if (k > 64) {
        cout << "0\n";
        return ;
    }
    int b = __lg(n);
    ll ans = 0;
    for (int i = 1; i <= b; i++) {
        int len = max(i, (k + 1) - (i - 1));
        for (int j = len - 1; j <= b - 1; j++) {
            ans += C(j, i - 1);
        }
    }
    if (b + 1 > k) {
        ans++;
    }
    cout << ans << "\n";
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