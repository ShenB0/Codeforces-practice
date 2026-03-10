#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;
int ls[N], rs[N], fa[N];
ll dp1[N], dp2[N];//dp1[]:遍历完子树回到fa的时间;dp2[]:从x到0的dp1前缀和
void dfs1(int u) {
    int l = ls[u], r = rs[u];
    if (l == 0) { 
        dp1[u] = 1;
        return;
    }
    dfs1(l);
    dfs1(r);
    dp1[u] = (dp1[l] + dp1[r] + 3) % MOD;//u->l,u->r,u->fa[u]
}
void dfs2(int u) {
    int l = ls[u], r = rs[u];
    if (l) {
        dp2[l] = (dp1[l] + dp2[u]) % MOD;
        dfs2(l);
    }
    if (r) {
        dp2[r] = (dp1[r] + dp2[u]) % MOD;
        dfs2(r);
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        ls[i] = rs[i] = fa[i] = 0;
        dp1[i] = dp2[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> ls[i] >> rs[i];
        if (ls[i]) {
            fa[ls[i]] = i;
            fa[rs[i]] = i;
        }
    }
    fa[1] = 0;
    dfs1(1);
    dp2[0] = 0;
    dp2[1] = dp1[1];
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        ll ans;
        if (ls[i] == 0) {
            ans = (1 + dp2[fa[i]]) % MOD;
        } else {
            ans = (dp1[i] + dp2[fa[i]]) % MOD;
        }
        cout << ans << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}