#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << "0\n";
        return ;
    }
    bool flag = ((n & 1) ? true : false);
    int cur = 0;
    while (n) {
        cur++;
        n >>= 1;
        if (n == k) {
            cout << cur << "\n";
            return ;
        }
        if (flag && k == n + 1) {
            cout << cur << "\n";
            return ;
        }
        if (n & 1) flag = true;
    }
    cout << "-1\n";
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