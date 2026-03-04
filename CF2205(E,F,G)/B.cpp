//质因数分解
//因为质数不可被分解，所以k要是n的质因子去重后的lcm方为最小也就是Π质因数
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
int divisor(int x){
    ll ans = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            ans *= i;
        }
    }
    if (x > 1) {
        ans *= x;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    cout << divisor(n) << "\n";
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