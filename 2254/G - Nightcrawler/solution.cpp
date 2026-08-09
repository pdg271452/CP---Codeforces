#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=2e5+10;
int n,a[N],p[N];
priority_queue<int>q[N],qa;
void solve() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)cin>>p[i];
	for(int i=n;i>=1;i--) {
		if(!q[i].size())q[i].push(-a[i]);
		else {
			int x=-q[i].top();
			q[i].pop();
			q[i].push(-max(a[i],x));
			qa.push(min(a[i],x));
		}
		if(i>1) {
			int fa=p[i];
			if(q[fa].size()<q[i].size())swap(q[fa],q[i]);
			while(q[i].size()) {
				int x=q[i].top();
				q[i].pop();
				q[fa].push(x);
			}
		}
	}
	for(int i=1;i<q[1].size();i++)cout<<-1<<" ";
	int sum=0;
	while(q[1].size()) {
		sum-=q[1].top();
		q[1].pop();
	}
	cout<<sum<<" ";
	while(qa.size()) {
		sum+=qa.top();
		qa.pop();
		cout<<sum<<" ";
	}
	cout<<endl;
	return;
}
 
signed main() {
	cin>>T;
	while(T--)solve();
	return 0;
}