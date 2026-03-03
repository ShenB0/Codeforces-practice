//只要初始不为非递减，那么就保留那个"凸起"即可删除剩下所有，否则一个都删不掉
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    bool flag = false;
    int pre = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < pre) {
            flag = true;
        }
        pre = a[i];
    }
    if (flag) {
        cout << "1\n";
    } else {
        cout << n << "\n";
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