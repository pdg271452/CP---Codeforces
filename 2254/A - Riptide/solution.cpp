#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
int t,a[3];
cin>>t;
while(t--){
cin>>a[0]>>a[1]>>a[2];
sort(a,a+3);
cout<<min(a[2]-a[1],a[1]-a[0])<<endl;
}
}