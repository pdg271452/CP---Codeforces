#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int , int> freq;
    int max_init=0;
    int oc = 0;
    int em0 = 0;
    int em1 = 0;
    for(int i=0; i<n; ++i){
        cin>>a[i];
        max_init = max(max_init , ++ freq[a[i]]);
        if(a[i]%2 !=0){
            oc++;
            
        }
        else{
            if((a[i]/2)% 2 == 0){
                em0++;
            }
            else{
                em1++;
            }
        }
        
    }
    int ans = max({max_init , oc , em0, em1});
    cout<<ans<< "
" ;
    
}
 
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}