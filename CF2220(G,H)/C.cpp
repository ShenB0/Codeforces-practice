//栈模拟
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
char stk[N];
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int top = -1;
    for (int i = 0; i < n; i++) {
        if (top != -1 && s[i] == s[top]) {
            top--;
            continue;
        }
        top++;
        s[top] = s[i];
    }
    if (top != -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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