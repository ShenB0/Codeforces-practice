#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) one++;
        if (a[i] == 0) zero++;
    }
    if (zero == 1 || (zero > 1 && one)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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