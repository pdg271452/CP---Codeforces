#include<bits/stdc++.h>
using namespace std;
#define LL long long
bool OP(){
	string s;
	set<char> se;
	int n,m;
	cin >> n >> m;
	bool ans = true;
	while(n--){
		cin >> s;
		se.insert(s[0]-'a'+'A');
	}
	while(m--){
		cin >> s;
		for(char ch:s){
			if(!se.count(ch)){
				ans = false;
			}
		}
	}
	return ans;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		if(OP()) cout << "YES
";
		else cout << "NO
";
	}
	return 0;
}