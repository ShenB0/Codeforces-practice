#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int i = 0;
    if (n & 1) {
        if (s[0] == 'b') {
            cout << "NO\n";
            return ;
        }
        i = 1;
    }
    for (; i < n - 1; i += 2) {
        if (s[i] == s[i + 1] && s[i] != '?') {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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