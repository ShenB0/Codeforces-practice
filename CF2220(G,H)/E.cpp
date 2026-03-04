//注意1<y,z<x也就是不能分解为1乘以本身
//非递减可以用issorted判断(C20,algorithm)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
int a[N];
int factor(int x){
    if (x == 1) return 1;
    int fac = 0;
    int cnt = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            cnt++;
            fac = i;
        }
        if (cnt > 1) return 0;
    }
    if (x > 1) {//1不行
        cnt++;
        fac = x;
        if (cnt > 1) return 0;
    }
    return fac;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pre = -1;
    bool inc = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < pre) inc = false;
        pre = a[i];
    }
    if (inc) {
        cout << "Bob\n";
        return ;
    }
    vector<int> div;
    for (int i = 0; i < n; i++) {
        int fac = factor(a[i]);
        if (!fac) {
            cout << "Alice\n";
            return ;
        }
        div.push_back(fac);
    }
    pre = -1;
    for (auto& e : div) {
        if (pre > e) {
            cout << "Alice\n";
            return ;
        }
        pre = e;
    }
    cout << "Bob\n";
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