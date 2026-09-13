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
 
ll eval_indices(int n, const vi& idx) {
    int c[3] = {0, 0, 0};
    int curr_X = 0;
    int prev = 0;
    for (int p : idx) {
        int len = p - prev;
        c[curr_X] += len;
        if (p % 2 == 0) {
            curr_X = (curr_X + 1) % 3;
        } else {
            curr_X = (curr_X + 2) % 3;
        }
        prev = p;
    }
    c[curr_X] += (n + 1 - prev);
 
    ll cost = 0;
    for (int v = 0; v < 3; ++v) {
        cost += (ll)c[v] * (c[v] - 1) / 2;
    }
    return cost;
}
 
void solve() {
    int Dr_Agos_pixels;
    cin >> Dr_Agos_pixels;
    int n = Dr_Agos_pixels;
 
    ll best_cost = LINF;
    vi best_idx;
 
    auto check = [&](const vi& idx) {
        ll cost = eval_indices(n, idx);
        if (cost < best_cost) {
            best_cost = cost;
            best_idx = idx;
        }
    };
 
    // Theoretical lower bound
    int N = n + 1;
    int q = N / 3;
    int r = N % 3;
    ll opt_cost = (ll)r * (q + 1) * q / 2 + (ll)(3 - r) * q * (q - 1) / 2;
 
    if (n <= 30) {
        // Brute force all subsets of size 1, 2, 3
        for (int i = 1; i <= n; ++i) {
            check({i});
            for (int j = i + 1; j <= n; ++j) {
                check({i, j});
                for (int k = j + 1; k <= n; ++k) {
                    check({i, j, k});
                }
            }
        }
    } else {
        // Check size 1 around midpoint
        int mid = (n + 1) / 2;
        for (int i = max(1, mid - 5); i <= min(n, mid + 5); ++i) {
            check({i});
        }
 
        // Check size 2 around n/3 and 2n/3
        int t1 = (n + 1) / 3;
        int t2 = 2 * (n + 1) / 3;
        for (int i = max(1, t1 - 8); i <= min(n, t1 + 8); ++i) {
            for (int j = max(i + 1, t2 - 8); j <= min(n, t2 + 8); ++j) {
                check({i, j});
                if (best_cost == opt_cost) goto done;
            }
        }
 
        // Check size 3 with small prefix
        for (int i = 1; i <= 6; ++i) {
            for (int j = max(i + 1, i + t1 - 8); j <= min(n, i + t1 + 8); ++j) {
                for (int k = max(j + 1, j + t1 - 8); k <= min(n, j + t1 + 8); ++k) {
                    check({i, j, k});
                    if (best_cost == opt_cost) goto done;
                }
            }
        }
 
        // Check size 3 with small suffix
        for (int k = n; k >= max(1, n - 5); --k) {
            for (int j = max(1, k - t1 - 8); j <= min(k - 1, k - t1 + 8); ++j) {
                for (int i = max(1, j - t1 - 8); i <= min(j - 1, j - t1 + 8); ++i) {
                    check({i, j, k});
                    if (best_cost == opt_cost) goto done;
                }
            }
        }
 
        // Check size 3 around 4 equal parts: n/4, 2n/4, 3n/4
        int q1 = (n + 1) / 4;
        int q2 = 2 * (n + 1) / 4;
        int q3 = 3 * (n + 1) / 4;
        for (int i = max(1, q1 - 5); i <= min(n, q1 + 5); ++i) {
            for (int j = max(i + 1, q2 - 5); j <= min(n, q2 + 5); ++j) {
                for (int k = max(j + 1, q3 - 5); k <= min(n, q3 + 5); ++k) {
                    check({i, j, k});
                    if (best_cost == opt_cost) goto done;
                }
            }
        }
    }
 
done:
    string ans(n, '0');
    for (int p : best_idx) {
        ans[p - 1] = '1';
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