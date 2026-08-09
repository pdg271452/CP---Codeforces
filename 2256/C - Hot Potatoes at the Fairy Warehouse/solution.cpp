#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    long long k;
    cin >> n >> k;
    string s;
    cin >> s;
 
    int len = 2 * n;
    bool has_zero = false;
    for (char c : s) {
        if (c == '0') {
            has_zero = true;
            break;
        }
    }
 
    if (!has_zero) {
        cout << n << " " << n << "
";
        return;
    }
 
    int ze = 0;
    int zo = 0;
 
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0') {
        
            long long L = 0;
            int idx = (i - 1 + len) % len;
            while (s[idx] == '1') {
                L++;
                idx = (idx - 1 + len) % len;
            }
 
            long long m = min(L, k);
            long long S;
            if (m == 0) {
                S = 0;
            } else if (m % 2 == 1) {
                S = m;
            } else {
                S = m - 1;
            }
 
            int fp = (i - S) % len;
            if (fp < 0) fp += len;
 
    
            if (fp % 2 == 1) {
                ze++;
            } else {
                zo++;
            }
        }
    }
 
    int rs = n - ze;
    int bs = n - zo;
 
    cout << rs << " " << bs << "
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}