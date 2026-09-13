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
 
void solve() {
    int n;
    cin >> n;
    vi p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
 
    vi S;
    for (int i = 1; i <= n; ++i) {
        if (p[i] != i) {
            S.pb(i);
        }
    }
 
    if (S.empty()) {
        cout << "YES
";
        return;
    }
 
    int k = sz(S);
    bool possible = true;
    for (int j = 0; j < k; ++j) {
        if (p[S[j]] != S[k - 1 - j]) {
            possible = false;
            break;
        }
    }
 
    cout << (possible ? "YES
" : "NO
");
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