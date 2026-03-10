#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        int x = i;
        while (x) {
            if (x == a[i]) {
                ok = true;
                break;
            }
            x >>= 1;
        }
        x = i;
        while (x <= n) {
            if (x == a[i]) {
                ok = true;
                break;
            }
            x <<= 1;
        }
        if (!ok) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
    return ;
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