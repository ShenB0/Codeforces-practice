#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  3e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = a[0], r = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] <= l || a[i] > r + 1) {
            cnt++;
            l = r = a[i];
            continue;
        }
        r = a[i];
    }
    cout << cnt << "\n";
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