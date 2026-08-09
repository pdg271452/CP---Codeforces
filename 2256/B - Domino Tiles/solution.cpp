#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
constexpr int MOD = 998244353;
 
// Counts how many alternating patterns (0101... or 1010...) are compatible with the string
long long count_valid_patterns(const string& s, int start_idx) {
    bool valid_A = true; // Pattern starting with '0'
    bool valid_B = true; // Pattern starting with '1'
 
    int pos = 0;
    for (size_t i = start_idx; i < s.length(); i += 2) {
        char expected_A = (pos % 2 == 0) ? '0' : '1';
        char expected_B = (pos % 2 == 0) ? '1' : '0';
 
        if (s[i] != '?') {
            if (s[i] != expected_A) valid_A = false;
            if (s[i] != expected_B) valid_B = false;
        }
        pos++;
    }
 
    return (valid_A ? 1 : 0) + (valid_B ? 1 : 0);
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    long long w_odd = count_valid_patterns(s, 0);  // 0-indexed odd positions (1st, 3rd, 5th...)
    long long w_even = count_valid_patterns(s, 1); // 0-indexed even positions (2nd, 4th, 6th...)
 
    long long ans = (w_odd * w_even) % MOD;
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