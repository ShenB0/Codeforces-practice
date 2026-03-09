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
    int mx = (s.front() == '1' ? 1 : 0) + (s.back() == '1' ? 1 : 0);
    int mi = mx;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == '1' && s[i + 1] == '1') {
            s[i] = '1';
        }
        mx += (s[i] == '1' ? 1 : 0);
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == '1' && s[i + 1] == '1') {
            s[i] = '0';
        }
        mi += (s[i] == '1' ? 1 : 0);
    }
    cout << mi << " " << mx << "\n";
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