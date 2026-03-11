//可以用bitmask优化
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  5e4 + 10;
bool vis[N][26];
void solve(){
    int n, k;
    cin >> n >> k;
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < k; j++) {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            vis[i][s[i] - 'a'] = true;
        }
    }
    vector<int> div;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    for (int d : div) {
        bool ok = true;
        int i = n / d;
        vector<char> ans(n);
        for (int j = 0; j < d; j++) {
            bool flag = false;
            for (int c = 0; c < 26; c++) {
                if (!vis[j][c]) continue;
                bool found = true;
                for (int l = 0; l < i; l++) {
                    if (!vis[l * d + j][c]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    for (int l = 0; l < i; l++) {
                        ans[l * d + j] = 'a' + c;
                    }
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n; i++) {
                cout << ans[i];
            }
            cout << "\n";
            return ;
        }   
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