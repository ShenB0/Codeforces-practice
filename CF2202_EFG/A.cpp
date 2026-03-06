#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    ll x, y;
    cin >> x >> y;
    ll y_x = 0;
    if (y < 0) {
        y_x = 4 * (-y);
    } else if (y > 0) {
        y_x = 2 * y;
    }
    ll delta = x - y_x;
    if (delta >= 0 && delta % 3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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