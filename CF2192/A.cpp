#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 1;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) cnt++;
        else flag = true;
    }
    if (s[0] == s[n - 1] || !flag) cout << cnt << "\n";
    else cout << cnt + 1 << "\n";
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