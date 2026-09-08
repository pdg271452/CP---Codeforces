/**
 * @file main.cpp
 * @author Pranjal Gupta
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
 
    ll d = y - x;
    ll total = 0;
 
    ll l1 = x;
    ll r1 = min(x + k - 1, d);
 
    for (ll  m = l1; m <= r1; ++m) {
        total += (d % m);
    }
 
    ll l2 = max(x, d + 1);
    ll r2 = x + k - 1;
 
    if (l2 <= r2) {
        ll count = r2 - l2 + 1;
        total += count * d;
    }
 
    cout << total << "
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