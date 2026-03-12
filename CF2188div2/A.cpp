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
    vector<int> q;
    vector<bool> vis(n + 1, false);
    q.push_back(1);
    for (int i = n - 1; i >= 1; i--) {
        if (q.back() + i <= n && !vis[q.back() + i]) {
            vis[i + q.back()] = true;
            q.push_back(i + q.back());
            continue;
        } else {
            vis[q.back() - i] = true;
            q.push_back(q.back() - i);
        }
    }   
    reverse(q.begin(), q.end());
    for (auto i : q) {
        cout << i << " ";
    }
    cout << "\n";
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