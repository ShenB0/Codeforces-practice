#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int one = 0;
    int cur = 0;
    for (int r = 0; r < n; r++) {
        if (s[r] == '1') {
            if (one == 0) {
                one += (cur + 1) / 3;
            } else {
                one += cur / 3;
            }
            one++;
            cur = 0;
        } else {
            cur++;
        }
    }
    if (one == 0) {
        one += (cur - 1) / 3 + 1;
    } else {
        one += (cur + 1) / 3;
    }
    cout << one << "\n";
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