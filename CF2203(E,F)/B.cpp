#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    ll x;
    cin >> x;
    int dig = 0;
    vector<ll> q;
    while (x) {
        ll b = x % 10;
        x /= 10;
        q.push_back(b);
        dig++;
    }
    ll head = q.back();
    vector<ll> v(q.begin(), q.end());
    v.back() = 1LL;
    sort(q.begin(), q.end());
    ll sum1 = 0;
    ll cnt1 = 0;
    bool flag = false;
    for (auto p : q) {
        if ((sum1 + p) < 10) {
            if (p == head) {
                flag = true;
            }
            sum1 += p;
            cnt1++;
        } else {
            break;
        }
    }
    if (cnt1 == dig) {
        cout << "0\n";
        return ;
    }
    sort(v.begin(), v.end());
    ll sum2 = 0;
    ll cnt2 = 0;
    for (auto p : v) {
        if ((sum2 + p) < 10) {
            sum2 += p;
            cnt2++;
        } else {
            break;
        }
    }
    ll res1 = dig - cnt1;
    ll res2 = dig - cnt2 + 1;
    cout << (flag ? min(res1, res2) : res2) << "\n";
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