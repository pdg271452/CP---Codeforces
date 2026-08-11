#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
 
    if (n % 2 != 0) {
        cout << "NO
";
        return;
    }
 
    long long min_odd = 2e18; // Infinity substitute
    long long max_even = -1;
 
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            min_odd = min(min_odd, w[i]);
        } else {
            max_even = max(max_even, w[i]);
        }
    }
 
    if (min_odd - max_even >= 2) {
        cout << "YES
";
    } else {
        cout << "NO
";
    }
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