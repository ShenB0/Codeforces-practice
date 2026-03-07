//栈保留后缀最短序列(后缀最优性)通过从后向前枚举左端点来实现对每个子串的统计
//坐标差本身就是贡献
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
    stack<int> stk;//当前栈里的每个元素 j 都代表 未来还没有被消除的元素
    ll ans = 0, num = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] + 1 == a[stk.top()]) {
            num -= n - stk.top();//对元素 j，它能覆盖的子段数量 = (n - j)
            stk.pop();
        }
        stk.push(i);
        num += n - i;//
        ans += num;
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
