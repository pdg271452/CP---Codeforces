/**
 * @file main.cpp
 * @author Pranjal Gupta
 */
 
#include <bits/stdc++.h>
using namespace std;
 
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
 
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
 
void solve() {
    int n;
    cin >> n;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    vi diff(n + 2, 0);
    for (int k = 1; k <= n; k++) {
        ll L = a[k] * k;
        if (L < n) {
            ll R = min((ll)n - 1, (a[k] + 1) * k - 1);
            diff[L]++;
            diff[R + 1]--;
        }
    }
 
    vi b;
    int cf = 0;
    for (int y = 0; y < n; y++) {
        cf += diff[y];
        if (cf == 0) {
            b.pb(y);
        }
    }
 
    cout << sz(b) << "
";
    for (int i = 0; i < sz(b); i++) {
        cout << b[i] << (i + 1 == sz(b) ? "" : " ");
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