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
const int MOD = 1e9 + 7;
 
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
 
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
 
    vi S;
    int cf = 0;
    vi in_S(n, 0);
    for (int y = 0; y < n; y++) {
        cf += diff[y];
        if (cf == 0) {
            S.pb(y);
            in_S[y] = 1;
        }
    }
    vi pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + in_S[i];
    }
 
    auto ca = [&](int L, int R) {
        if (L > R) return 0;
        L = max(0, L);
        R = min(n - 1, R);
        if (L > R) return 0;
        return pref[R + 1] - pref[L];
    };
 
    vpi intervals;
    for (int k = 1; k <= n; k++) {
        for (ll v = 0; v < a[k]; v++) {
            ll L = v * k;
            if (L >= n) break;
            ll R = min((ll)n - 1, (v + 1) * k - 1);
            if (ca(L, R) > 0) {
                int fe = lower_bound(all(S), L) - S.begin();
                int last_elem = upper_bound(all(S), R) - S.begin() - 1;
                intervals.pb({fe, last_elem});
            }
        }
    }
 
    sort(all(intervals), [](const pii &x, const pii &y) {
        if (x.second != y.second) return x.second < y.second;
        return x.first > y.first;
    });
 
    vpi minimal_intervals;
    int max_L = -1;
    for (auto &iv : intervals) {
        if (iv.first > max_L) {
            minimal_intervals.pb(iv);
            max_L = iv.first;
        }
    }
 
    int m = sz(S);
    int num_iv = sz(minimal_intervals);
    vi latest_req(m + 1, -1);
    int ptr = 0;
    int cur_max = -1;
    for (int i = 0; i <= m; i++) {
        while (ptr < num_iv && minimal_intervals[ptr].second < i) {
            cur_max = max(cur_max, minimal_intervals[ptr].first);
            ptr++;
        }
        latest_req[i] = cur_max;
    }
 
    vll dp(m + 1, 0);
    vll pref_dp(m + 2, 0);
    dp[0] = 1;
    pref_dp[1] = 1;
 
    for (int i = 1; i <= m; i++) {
        int req = latest_req[i - 1];
        int lower_bound_j = req + 1; // can transition from j in [lower_bound_j, i-1]
        if (lower_bound_j <= i - 1) {
            dp[i] = (pref_dp[i] - pref_dp[lower_bound_j] + MOD) % MOD;
        } else {
            dp[i] = 0;
        }
        pref_dp[i + 1] = (pref_dp[i] + dp[i]) % MOD;
    }
 
    ll ans = 0;
    int final_req = latest_req[m];
    for (int j = final_req + 1; j <= m; j++) {
        ans = (ans + dp[j]) % MOD;
    }
 
    cout << ans << "
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