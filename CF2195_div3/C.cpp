//只有在我改变了一个节点时才跳，而不是一直跳，因为我跳的前提就是因为我改了中间那个可以让两边都不动
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  3e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1] || (a[i] + a[i + 1]) == 7) {
            ans++;
            i++;
        }
    }
    cout << ans << "\n";
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