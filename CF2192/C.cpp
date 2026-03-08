#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const ll INF = 1LL << 60;
const int N =  2e5 + 10;
ll a[N], suf[N], pre[N];
void solve(){
    ll n, h, k;
    cin >> n >> h >> k;
    ll sum = 0;
    pre[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        pre[i] = min(pre[i - 1], a[i]);
    }
    suf[n + 1] = suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = max(suf[i + 1], a[i]);
    }
    ll t = h / sum * (k + n);
    h = h % sum;
    if (h == 0) {
        cout << t - k << "\n";
        return ;
    }
    for (int i = 1; i <= n; i++) {
        h -= a[i];
        if (h <= 0 || h - (suf[i + 1] - pre[i]) <= 0) {
            cout << t + i << "\n";
            return ;
        }
    }
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