#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N], b[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if (is_sorted(a, a + n)) {
        cout << "-1\n";
        return ;
    }
    sort(b, b + n);
    int mi = *min_element(a, a + n);
    int mx = *max_element(a, a + n);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans = min(ans, max(mx - a[i], a[i] - mi));//对于每一个元素，他应该选择差值更大的那一方来做跳跃，而对于全局应选择最小来保证所有点都可以通过最大最小值来跳跃
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