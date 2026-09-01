#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;cin>>t;
 while(t--){
  int n,m;cin>>n>>m;
  vector<int>c(m+1);
  for(int i=0,x;i<n;i++)cin>>x,c[x]++;
  int s=0,a=0;
  for(int x=m;x;x--){
   a=max(a,c[x]+s+(2*x<=m?c[2*x]:0));
   s+=c[x];
  }
  cout<<a<<"
";
 }
}
 