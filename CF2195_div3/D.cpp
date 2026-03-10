#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  3e5 + 10;
ll f[N], g[N], diff[N], a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 0; i < n - 1; i++) {
        g[i] = f[i + 1] - f[i];
    }
    for (int i = 0; i < n - 2; i++) {
        diff[i] = g[i + 1] - g[i];
    }
    for (int i = 0; i < n - 2; i++) {
        a[i + 1] = diff[i] / 2;
    }
    a[0] = f[n - 1], a[n - 1] = f[0];
    for (int i = 1; i < n - 1; i++) {
        a[0] -= a[i] * (n - i - 1);
        a[n - 1] -= i * a[i];
    }
    a[0] /= n - 1;
    a[n - 1] /= n - 1;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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