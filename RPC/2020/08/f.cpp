#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// your code goes here
	ios::sync_with_stdio(0),cin.tie(0);
	ll t,rta;
	cin>>t;
	while(t--){
		cin>>rta;
		rta =(rta+1)*(rta+1)-1;
		cout<<rta<<endl;
	}
	return 0;
}