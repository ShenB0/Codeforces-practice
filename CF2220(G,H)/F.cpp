//优先队列
//重点在于mx和ans[i]不一样，mx表示只在已有的选取i个，ans表示需求i-1个
//前缀最大值是因为对于yi它可以存在于任意小于yi的情况中，所以需要前缀极值
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
ll ans[N];
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].second >> vec[i].first;
    }
    sort(vec.begin(), vec.end(), greater<pair<ll, int>>());
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll sum = 0;
    int id = 0;
    memset(ans, 0, sizeof(ans));
    ll mx = 0;
    for (int i = n; i >= 0; i--) {
        while (id < n && vec[id].first >= i) {
            ll x = vec[id].second;
            q.push(x);
            sum += x;
            id++;
        }
        while ((int)q.size() > i + 1) {
            sum -= q.top();
            q.pop();
        }
        mx = max(mx, sum);
        ans[i] = sum;
        if ((int)q.size() > i) {
            ll mi = q.top();
            ans[i] = sum - mi;
            sum -= mi;
            q.pop();
        } else {
            ans[i] = sum;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = max(ans[i - 1], ans[i]);
    }
    while (m--) {
        ll x;
        int y;
        cin >> x >> y;
        cout << max(mx, ans[y] + x) << " ";
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