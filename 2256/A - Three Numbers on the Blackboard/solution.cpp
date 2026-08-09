#include <iostream>
#include <algorithm>
 
using namespace std;
 
void solve() {
    long long a[3];
    if (!(cin >> a[0] >> a[1] >> a[2])) return;
    
    // Sort so that x <= y <= z# pranjal
    sort(a, a + 3);
    
    long long x = a[0];
    long long y = a[1];
    long long z = a[2];
    
    // Minimum range is min(z - x, y) # pranjal
    long long ans = min(z - x, y);
    cout << ans << "
";
}
 
int main() {
    // Fast I/O #pranjal
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