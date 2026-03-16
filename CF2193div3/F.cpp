#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const ll INF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
ll dp[N][2];//dp[i][0]:到最高点;dp[i][1]:到最低点
ll dist(ll x1, ll y1, ll x2, ll y2) {
    return llabs(x1 - x2) + llabs(y1 - y2);
}
void solve(){
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<ll> X(n);
    map<ll, vector<ll>> mp;
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < n; i++) {
        ll y;
        cin >> y;
        mp[X[i]].push_back(y);
    }
    dp[0][0] = dp[0][1] = 0;
    ll cur = 1;
    ll pre_x = ax;
    ll pre_mi = ay, pre_mx = ay;
    for (auto& [x, Y] : mp) {
        ll mx = 0, mi = INF;
        for (auto& y : Y) {
            mi = min(y, mi);
            mx = max(y, mx);
        }
        ll h = mx - mi;
        dp[cur][0] = min(
            dp[cur - 1][0] + dist(pre_x, pre_mx, x, mi), 
            dp[cur - 1][1] + dist(pre_x, pre_mi, x, mi)
        ) + h;
        dp[cur][1] = min(
            dp[cur - 1][0] + dist(pre_x, pre_mx, x, mx), 
            dp[cur - 1][1] + dist(pre_x, pre_mi, x, mx)
        ) + h;
        cur++;
        pre_x = x;
        pre_mx = mx, pre_mi = mi;
    }
    cout << min(
        dp[cur - 1][0] + dist(pre_x, pre_mx, bx, by), 
        dp[cur - 1][1] + dist(pre_x, pre_mi, bx, by)
    ) << "\n";
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