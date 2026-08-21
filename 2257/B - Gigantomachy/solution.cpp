#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[105],b[105];
int main(){
cin>>t;
while(t--){
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int j=1;j<=m;j++)  cin>>b[j];
cout<<(a[1]+n-1>=b[1]+m-1?1:2)<<endl;
}
return 0;
}