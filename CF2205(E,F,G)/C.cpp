//模拟
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  1e6 + 10;
bool vis[N];
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> blog(n);
    vector<bool> use(n, false);
    vector<int> q;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> tmp(m);
        for (int j = 0; j < m; j++) {
            cin >> tmp[j];
            vis[tmp[j]] = false;
        }
        set<int> st;
        for (int j = m - 1; j >= 0; j--) {
            if (st.find(tmp[j]) == st.end()) {
                blog[i].push_back(tmp[j]);
                st.insert(tmp[j]);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        int id = -1;
        vector<int> best;
        for (int i = 0; i < n; i++) {
            if (use[i]) continue;
            vector<int> tmp;
            for (int p : blog[i]) {
                if (!vis[p]) tmp.emplace_back(p);
            }
            if (id == -1 || best > tmp) {
                best = tmp;
                id = i;
            }
        }
        if (id != -1) {
            use[id] = true;
            for (int p : best) {
                if (!vis[p]) {
                    q.emplace_back(p);
                    vis[p] = true;
                }
            }
        }
    }
    for (auto& e : q) {
        cout << e << " ";
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