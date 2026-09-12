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
 
struct Node {
    int cnt = 0;
    ll sum = 0;
    ll need = 0;       
    int ffe = 0;   
    ll fs = 0; 
};
 
const int MAXN = 200005;
ll a[MAXN];
Node tree[4 * MAXN];
 
pair<int, ll> qs(int node, int l, int r, ll S) {
    if (tree[node].cnt == 0) {
        return {0, S};
    }
    if (S >= tree[node].need) {
        return {0, S + tree[node].sum};
    }
    if (l == r) {
        return {1, tree[node].sum};
    }
 
    int mid = (l + r) / 2;
    int lc = 2 * node, rc = 2 * node + 1;
 
    if (tree[lc].cnt == 0) {
        return qs(rc, mid + 1, r, S);
    }
    if (tree[rc].cnt == 0) {
        return qs(lc, l, mid, S);
    }
 
    if (S >= tree[lc].need) {
        return qs(rc, mid + 1, r, S + tree[lc].sum);
    } else {
        auto left_res = qs(lc, l, mid, S);
        return {left_res.first + (tree[node].ffe - tree[lc].ffe), tree[node].fs};
    }
}
 
void pull(int node, int l, int r) {
    int lc = 2 * node, rc = 2 * node + 1;
    if (tree[lc].cnt == 0) {
        tree[node] = tree[rc];
        return;
    }
    if (tree[rc].cnt == 0) {
        tree[node] = tree[lc];
        return;
    }
 
    tree[node].cnt = tree[lc].cnt + tree[rc].cnt;
    tree[node].sum = tree[lc].sum + tree[rc].sum;
    tree[node].need = max(tree[lc].need, tree[rc].need - tree[lc].sum);
 
    int mid = (l + r) / 2;
    auto right_res = qs(rc, mid + 1, r, tree[lc].fs);
    tree[node].ffe = tree[lc].ffe + right_res.first;
    tree[node].fs = right_res.second;
}
 
void act(int node, int l, int r, int pos, ll val) {
    if (l == r) {
        tree[node].cnt = 1;
        tree[node].sum = val;
        tree[node].need = val;
        tree[node].ffe = 0;
        tree[node].fs = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        act(2 * node, l, mid, pos, val);
    } else {
        act(2 * node + 1, mid + 1, r, pos, val);
    }
    pull(node, l, r);
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vi p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= 4 * n; i++) {
        tree[i] = Node();
    }
 
    vi ans(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        int idx = p[i];
        act(1, 1, n, idx, a[idx]);
        ans[i] = tree[1].ffe;
    }
 
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
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