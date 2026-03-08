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
    vector<int> one, zero;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zero.push_back(i + 1);
        else one.push_back(i + 1);
    }
    int cnt = zero.size();
    if (cnt & 1) {
        cout << cnt << "\n";
        for (auto e : zero) {
            cout << e << " ";
        }
        cout << "\n";
    } else if (n % 2 == 0) {
        cout << n - cnt << "\n";
        if (cnt == n) return ;
        for (auto e : one) {
            cout << e << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    
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