#include<bits/stdc++.h>
using namespace std;
int t,n,a[55]; 
map<int,int>m;
int ans=0;
int main() {
	cin>>t;
	while(t--){
		cin>>n;
		m.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			m[a[i]]++;
		} 
		ans=0;
		for(int i=1;i<=n;i++){ 
			ans+=min(m[a[i]],n-m[a[i]]+2)*a[i];
			m[a[i]]=0;
		}
		cout<<ans<<"
";
	}
    return 0;
}