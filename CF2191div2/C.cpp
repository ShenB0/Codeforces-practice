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
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
        }
    }
    string t = string(zero, '0') + string(n - zero, '1');
    if (t == s) {
        cout << "Bob\n";
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ans.push_back(i);
        }
    }
    cout << "Alice\n";
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i + 1 << " ";
    } 
    cout << "\n";
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