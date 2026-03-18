//可以用单调栈
//也可以用DSU
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N], L[N], R[N];
ll ans[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    n--;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i++) {
        v[i] = abs(a[i] - a[i - 1]);
    }
    v[0] = v[n + 1] = INF;
    L[0] = 0;
    for (int i = 1; i <= n; i++) {
        int pre = i - 1;
        while (pre != 0 && v[i] <= v[pre]) {
            pre = L[pre];
        }
        L[i] = pre;
    }
    R[n + 1] = n + 1;
    for (int i = n ; i >= 1; i--) {
        int pre = i + 1;
        while (pre != n + 1 && v[i] < v[pre]) {
            pre = R[pre];
        }
        R[i] = pre;
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        ans[v[i]] += 1LL * (i - L[i]) * (R[i] - i);
    }
    for (int i = n; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    // for (int i = 1; i <= n; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << L[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << R[i] << " ";
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