#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int s, k, m;
    cin >> s >> k >> m;
    int t = m % k;
    int c = m / k;
    int rem;
    if (c & 1) {
        rem = min(s, k);
    } else {
        rem = s;
    }
    cout << max(0, rem - t) << "\n";
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