//STL模拟
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int it = min_element(a + l, a + r) - a;
    int mi = a[it];
    vector<int> vec1(a + it, a + r);
    vec1.insert(vec1.end(), a + l, a + it);
    vector<int> vec2(a, a + l);
    vec2.insert(vec2.end(), a + r, a + n);
    //题解中的rotate(b.begin(), min_element(b.begin(), b.end()), b.end());更简洁
    int m = vec2.size();
    int i = 0;
    for (i = 0; i < m; i++) {
        if (vec2[i] > mi) {
            break;
        }
    }
    vec2.insert(vec2.begin() + i, vec1.begin(), vec1.end());
    for (auto& e : vec2) {
        cout << e << " ";
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