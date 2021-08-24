#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long ll;
typedef long long ld;


int main() {
	// your code goes here
	ios::sync_with_stdio(0),cin.tie(0);
	unsigned int t,n,r,x, mask;
	cin>>t;
	while(t--){
		cin >> n;
		mask = 0;
		for (int i = 0; i < 32; i++) {
			mask |= (1 << (n & 31));
			x = n & 1;
			n >>= 1;
			n |= (x << 31);
		}
		if(mask == 4294967295) cout<<"yes"<<endl;
		else cout << "no" << endl;

	}
	return 0;
}
