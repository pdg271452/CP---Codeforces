#include <iostream>
#include <string>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
 
    int ans = 0;
    for (int i = 0; i < n; i += k) {
        bool bl = true;
        for (int j = 0; j < k; ++j) {
            if (s[i + j] == '0') {
                bl = false;
                break;
            }
        }
        if (bl) {
            ans++;
        }
    }
 
   cout << ans << "
";
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}