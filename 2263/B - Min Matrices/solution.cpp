/**
 * @file main.cpp
 * @author Pranjal Gupta
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n || k > 2 * n - 1) {
        cout << -1 << "
";
        return;
    }
 
    int m = 2 * n - k;
    vector<vector<int>> A(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        A[i][i] = i + 1;
    }
    for (int i = m; i < n; ++i) {
        A[i][0] = m + (i - m + 1);
    }
 
    for (int j = m; j < n; ++j) {
        A[0][j] = n + (j - m + 1);
    }
    int next_val = k + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 0) {
                A[i][j] = next_val++;
            }
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << (j + 1 == n ? "" : " ");
        }
        cout << "
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