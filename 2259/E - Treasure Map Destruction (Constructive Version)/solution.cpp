#include "bits/stdc++.h"
using namespace std;
 
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n),m(n,1); for(int& x:a) cin >> x;
		for(int i=0,c=0;i<n;++i) {
			--c;
			c=max(c,a[i]);
			if(c>0) m[i]=0;
		}
		for(int i=n-1,c=0;i+1;--i) {
			--c;
			c=max(c,a[i]);
			if(c>0) m[i]=0;
		}
 
 
		bool p=0; for(int x:m) if(x==1) p=1;
		for(int i=0;i<n;++i) {
			if(a[i]==-1) continue;
			if(!((i-a[i]>=0&&m[i-a[i]]==1)||(i+a[i]<n&&m[i+a[i]]==1))) p=0;
		}
 
		if(p) {for(int x:m) cout << x; cout << '
';}
		else cout << "-1
";
	}
}