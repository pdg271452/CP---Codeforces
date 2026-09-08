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
    ll x, y;
    cin >> x >> y;
 
    ll s = x + y;
    ll by = -1;
 
    if ((y & s) == y) {
        by = y;
    }
 
    for (int i = 0; i <= 31; ++i) {
        if (((y >> i) & 1) == 0 && ((s >> i) & 1) == 1) {
            ll hm = ~((1LL << (i + 1)) - 1);
            if (((y & hm) & s) == (y & hm)) {
                ll cand = (y & hm) | (1LL << i);
                if (by == -1 || cand < by) {
                    by = cand;
                }
            }
        }
    }
 
    ll k = by - y;
    cout << s << " " << k << "
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