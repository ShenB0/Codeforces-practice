#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool sixty_seven = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 67) {
            sixty_seven = true;
        }
    }
    if (sixty_seven) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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