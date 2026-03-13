//时间戳+懒处理
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
ll a[N], b[N], last[N];
void solve(){
    int n, m;
    ll h;
    cin >> n >> m >> h;
    for (int i= 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    ll upd = 0;
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= m; i++) {
        int id;
        ll v;
        cin >> id >> v;
        if (last[id] < upd) {
            b[id] = a[id];
        }
        b[id] += v;
        last[id] = i;
        if (b[id] > h) {
            b[id] = a[id];
            upd = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (last[i] < upd) {
            b[i] = a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    //TLE
    // for (int i = 1; i <= n; i++) {
    //     cin >> a[i];
    //     b[i] = a[i];
    // }
    // for (int i = 0; i < m; i++) {
    //     int id; 
    //     ll v;
    //     cin >> id >> v;
    //     if (b[id] + v > h) {
    //         memcpy(b + 1, a + 1, sizeof(ll) * n);//copy(a, a + n, b);
    //     } else {
    //         b[id] += v;
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << "\n";
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