#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ones;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            ones.push_back(i);
        }
    }
 
    if (ones.empty()) {
        int fn = -1, ln = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (fn == -1) fn = i;
                ln = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i == fn || i == ln) {
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            }
        }
    } else {
        int p1 = ones.front();
        int pm = ones.back();
        int L = -1, R = -1;
        for (int i = 0; i < p1; i++) {
            if (a[i] == -1) {
                L = i;
                break;
            }
        }
        for (int i = n - 1; i > pm; i--) {
            if (a[i] == -1) {
                R = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i == L || i == R) {
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "
";
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