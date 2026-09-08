# include<bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zc = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            zc++;
        }
    }
 
    if (zc < 2) {
        cout << -1 << "
";
    } else {
        cout << a[0] + a[n - 1] << "
";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}