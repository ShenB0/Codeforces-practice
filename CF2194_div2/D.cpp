#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  2e5 + 10;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int one = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]) one++;
        }
    }
    int lim = one / 2;
    int cur = 0;
    int i, j;
    for (j = 0; j < m; j++) {
        for (i = n - 1; i >= 0; i--) {
            if (a[i][j] == 1) {
                cur++;
            }
            if (cur >= lim) {
                break;
            }
        }
        if (cur >= lim) {
            break;
        }
    } 
    cout << 1LL * lim * (one - lim) << "\n";
    string ans = string(j, 'R') + string(i, 'D') + "R" + string(n - i, 'D') + string(m - j - 1, 'R');
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