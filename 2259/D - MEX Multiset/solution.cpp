#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> zi;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] == 0){
            zi.push_back(i);
        }
    }
    if(zi.empty()){
        cout<<" YES 
";
        string s(n , 'A');
        cout<< s<< " 
 ";
        return;
    }
    if(zi.size() == 1){
        cout<<" NO
"; 
        return;
    }
    cout<< "YES
";
    string s(n , 'C');
    s[zi[0]] = 'A';
    s[zi[1]] = 'B';
    for(size_t i =2 ; i < zi.size() ; i++){
        s[zi[i]] = 'A';
    }
    cout<< s<< "
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