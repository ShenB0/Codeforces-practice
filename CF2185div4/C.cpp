#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cur = 1;
    int mx = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            cur++;
        } else if (a[i] == a[i - 1]){
            continue;
        } else {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    cout << max(cur, mx) << "\n";
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