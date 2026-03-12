#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int x, y;
    cin >> x >> y;
    if ((x & y) == 0) {
        cout << x << " " << y << "\n";
        return ;
    }
    int n = 63 - max(__builtin_clzll(x), __builtin_clzll(y));
    for (int i = n; i >= 0; i--) {
        if ((x & (1 << i)) && (y & (1 << i))) {
            int p1 = ((x >> (i + 1)) << (i + 1)) + (1 << i);
            int q1 = ((y >> (i + 1)) << (i + 1)) + ((1 << i) - 1);

            int p2 = ((x >> (i + 1)) << (i + 1)) + ((1 << i) - 1);
            int q2 = ((y >> (i + 1)) << (i + 1)) + (1 << i);

            int p3 = (((x >> i) + 1) << i); 
            int q3 = y;

            int p4 = x;
            int q4 = (((y >> i) + 1) << i);

            int p5 = (x >> (i + 1)) << (i + 1);
            int q5 = y;

            int p6 = x;
            int q6 = (y >> (i + 1)) << (i + 1);

            int d1 = abs(x - p1) + abs(y - q1);
            int d2 = abs(x - p2) + abs(y - q2);
            int d3 = abs(x - p3) + abs(y - q3);
            int d4 = abs(x - p4) + abs(y - q4);
            int d5 = abs(x - p5) + abs(y - q5);
            int d6 = abs(x - p6) + abs(y - q6);
            int mi = min(d1, min(d2, min(d3, min(d4, min(d5, d6)))));
            if (d1 == mi) {
                cout << p1 << " " << q1 << "\n";
            } else if (d2 == mi) {
                cout << p2 << " " << q2 << "\n";
            } else if (d3 == mi) {
                cout << p3 << " " << q3 << "\n";
            } else if (d4 == mi) {
                cout << p4 << " " << q4 << "\n";
            } else if (d5 == mi) {
                cout << p5 << " " << q5 << "\n";
            } else {
                cout << p6 << " " << q6 << "\n";
            }
            break;
        }
    }
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}