#include<bits/stdc++.h>
using namespace std;
int T,n,k;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(k==n-1){
			cout<<"-1
";
			continue;
		}
		for(int i=1;i<=k/2;i++)cout<<"0";
		cout<<"01";
		for(int i=1;i<=(k+1)/2;i++)cout<<"1";
		for(int i=k+3;i<=n;i++)cout<<((i-k-3)&1);
		cout<<"
";
	}
}