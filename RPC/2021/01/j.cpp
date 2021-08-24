#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long double ld;


int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	ll dp[1000001];
	dp[0]=0;
	dp[1]=1;
	for(ll i=2;i<1000001L;i++){
		dp[i]=dp[i-1];
		dp[i]+=(i*(i+1))/2;
	}
	int t,q;
	cin>>t;
	while(t--){
		cin>>q;
		cout<<dp[q]<<endl;
	}
	return 0;
}
