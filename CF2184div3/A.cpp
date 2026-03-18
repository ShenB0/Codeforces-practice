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
    cin >> n;
    if (n == 2) {
        cout << "2\n";
        return ;
    }
    if (n == 3) {
        cout << "3\n";
        return ;
    }
    if (n & 1)  cout << "1\n";
    else cout << "0\n";
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