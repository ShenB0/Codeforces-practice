#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    int avg = d / m + 1;
    cout << n / avg + (n % avg ? 1 : 0)<< "\n";
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