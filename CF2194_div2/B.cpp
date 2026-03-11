#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] / x;
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] + (sum - a[i] / x) * y);
    }
    cout << ans << "\n";

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}