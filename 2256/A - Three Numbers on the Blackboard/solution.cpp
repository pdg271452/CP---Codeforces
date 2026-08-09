#include <iostream>
#include <algorithm>
 
using namespace std;
 
void solve() {
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    
    long long x = a[0];
    long long y = a[1];
    long long z = a[2];
    
    if (z > x + y) {
        cout << y << "
";
    } else {
        cout << z - x << "
";
    }
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}