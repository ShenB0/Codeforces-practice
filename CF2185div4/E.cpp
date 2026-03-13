//也可以用哈希
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int rob[N], spi[N];
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> rob[i];
    }
    vector<pair<int, int>> l, r;
    for (int i = 0; i < m; i++) {
        cin >> spi[i];
    }
    sort(spi, spi + m);
    for (int i = 0; i < n; i++) {
        int id = upper_bound(spi, spi + m, rob[i]) - spi;
        if (id > 0) l.push_back({spi[id - 1] - rob[i], i});
        if (id < m) r.push_back({spi[id] - rob[i], i});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), greater<pair<int, int>>());
    string s;
    cin >> s;
    int cur = 0;
    int num = n;
    vector<bool> vis(n, false);
    for (auto op : s) {
        if (op == 'L') {
            cur--;
        } else {
            cur++;
        }
        while (!l.empty() && cur <= l.back().first) {
            if (!vis[l.back().second]) {
                vis[l.back().second] = true;
                num--;
            }
            l.pop_back();
        } 
        while (!r.empty() && cur >= r.back().first) {
            if (!vis[r.back().second]) {
                vis[r.back().second] = true;
                num--;
            }
            r.pop_back();
        } 
        cout << num << " ";
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