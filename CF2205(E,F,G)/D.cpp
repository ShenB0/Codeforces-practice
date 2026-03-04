//笛卡尔树
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  5e5 + 10;
int a[N];
struct node{
    int l, r;
}tree[N];
int dfs(int par){
    if(par == -1) return 0;
    auto [L, R] = tree[par];
    return 1 + max(dfs(L), dfs(R));
}
void solve(){
    int n;
    cin >> n;
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        tree[i].l = tree[i].r = -1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int pre = -1;
        while (!stk.empty() && a[stk.top()] < a[i]) {
            pre = stk.top();
            stk.pop();
        }
        if(pre != -1) tree[i].l = pre; 
        if(!stk.empty()) tree[stk.top()].r = i; 
        stk.push(i);
    }
    int root = -1;
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
    }
    int res = dfs(root);
    cout << n - res << "\n";
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