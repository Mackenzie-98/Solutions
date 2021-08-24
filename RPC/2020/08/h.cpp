#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// your code goes here
	ios::sync_with_stdio(0),cin.tie(0);
	ll t,n,r,x,aux,y;
	cin>>t;
	while(t--){

		cin >> n;
		n--;
		if (n == 0) {
			cout << 0 << ' ' << 0 << '\n';
		}else{
		 r =sqrt(n);
		 x = 0;
		if (r % 2 == 0) {
			x = r - (n - r*r);
		} else {
			x = -r + (n - r*r);
		}
		aux = (r+1)*(r+1) - r*r;
		y = -r / 2;
		if (r % 2 != 0) {
			if(n - r*r <= aux/2) {
				y += n - r*r;
			} else {
				y += aux/2;
				y -= n - r*r - aux/2;
			}
		}
		cout << x << ' ' << y << endl;
		}
	}
	return 0;
}
