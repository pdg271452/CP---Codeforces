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
const ll LINF = 2e18 + 7;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    if (m == 1) {
        ll max_val = -LINF;
        for (int i = 0; i < n; ++i) {
            max_val = max(max_val, a[i]);
        }
        cout << max_val << "
";
        return;
    }
 
    priority_queue<ll> max_pq;
    ll ss = 0;
    ll ans = -LINF;
 
    for (int i = 0; i < n; ++i) {
        if (sz(max_pq) == m - 1) {
            ll current_score = (ll)m * a[i] - ss;
            ans = max(ans, current_score);
        }
        if (sz(max_pq) < m - 1) {
            max_pq.push(a[i]);
            ss += a[i];
        } else if (!max_pq.empty() && a[i] < max_pq.top()) {
            ss -= max_pq.top();
            max_pq.pop();
            max_pq.push(a[i]);
            ss += a[i];
        }
    }
 
    cout << ans << "
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}