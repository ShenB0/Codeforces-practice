//找出最大值数量，顺序可以随意改变的情况，任意最大值都可能是winner
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  15;
int a[N];
void solve(){
    int n;
    cin >> n;
    int mx = -1, num = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            num = 1;
            continue;
        }
        if (a[i] == mx) {
            num++;
        }
    }
    cout << num << "\n";
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