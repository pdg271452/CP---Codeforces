#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    int count1 = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            count1++;
        }
    }
    int elsie_turns = (n - 1) / 2;
    if (count1 > elsie_turns) {
        cout << "Bessie
";
    } else {
        cout << "Elsie
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