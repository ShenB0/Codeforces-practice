#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  1e6 + 10;
int a[N], b[N];
int cnt[N << 1], num[N << 1];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + m; i++) {
        cnt[i] = 0;
        num[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    for (int i = 0; i < m; i++) 
        cin >> b[i];
    for (int i = 1; i <= n + m; i++) {
        if (!num[i]) continue;
        for (int j = i; j <= n + m; j += i) {
            cnt[j]+=num[i];
        }
    }
    int cntA = 0, cntB = 0, cntC = 0;
    for (int i = 0; i < m; i++) {
        int c = cnt[b[i]];
        if (c == 0) {
            cntB++;
        } else if (c == n) {
            cntA++;
        } else {
            cntC++;
        }
    }
    int havA = cntA + cntC / 2 + cntC % 2;
    int havB = cntB + cntC / 2;
    if (havA > havB) cout << "Alice\n";
    else cout << "Bob\n";
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