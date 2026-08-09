#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; 
    cin >> t;
 
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
 
        int s1= 0, s2 = 0;
        int s3 = 0, s4 = 0;
 
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
        
                s2++;
                s1 = max(s1, a[i]);
            } else {
     
                s4++;
                s3 = max(s3, a[i]);
            }
        }
 
      
        int s5 = s1 + s2;
        int s6 = s3 + s4;
 
        cout << max(s5,s6) << endl;
    }
 
    return 0;
}