#include <bits/stdc++.h>
using namespace std;
 
static const int MOD = 998244353;
 
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
 
long long modInverse(long long n) {
    return power(n, MOD - 2);
}
 
const int MAXN = 1000005;
long long fact[MAXN];
long long invFact[MAXN];
 
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
 
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int n0 = 0, n1 = 0;
    for (char c : s) {
        if (c == '0') n0++;
        else n1++;
    }
 
    if (n0 == 0 || n1 == 0) {
        cout << 1 << "
";
        return;
    }
 
    int k0 = 0, k1 = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            if (s[i] == '0') k0++;
            else k1++;
        }
    }
 
    long long ans0 = nCr(n0 - 1, k0 - 1);
    long long ans1 = nCr(n1 - 1, k1 - 1);
    long long ans = (ans0 * ans1) % MOD;
 
    cout << ans << "
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}