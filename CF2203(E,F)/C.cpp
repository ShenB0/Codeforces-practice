#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
bool check(ll s, ll m, ll c){
    ll acc = 0;
    for (int i = 60; i >= 0; i--) {
        acc <<= 1;
        if ((s >> i) & 1) acc += 1;
        if ((m >> i) & 1) acc -= min(c, acc);
    }
    return (acc == 0);
}
void solve(){
    ll s, m;
    cin >> s >> m;
    ll ans = -1;
    ll l = 0, r = (1LL << 60);
    while (l <= r) {
        ll mid = l + ((r - l) >> 1);
        if (check(s, m, mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
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