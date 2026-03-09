#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<bool> T(l, false);
    vector<int> d(m, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        T[t] = true;
    }
    for (int i = 0; i < l; i++) {//模拟
        sort(d.begin(), d.end(), greater<int>());
        int cur = min(n, m - 1);//m-1：剩一个最大化
        d[cur]++;
        if (T[i]) {
            *max_element(d.begin(), d.end()) = 0;
            n--;
        }
    }
    cout << *max_element(d.begin(), d.end()) << "\n";
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