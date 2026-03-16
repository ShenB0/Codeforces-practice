#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int n, s, x;
    cin >> n >> s >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    if (sum > s) {
        cout << "No\n";
        return ;
    } 
    if (sum == s) {
        cout << "Yes\n";
        return ;
    }
    int delta = s - sum;
    if (delta % x) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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