#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define sz size()
#define eps 0.000001
#define oo 2000000007
#define endl '\n'
#define bg begin()
#define nd end()
#define up upper_bound
#define lw lower_bound
#define debug(x) #x << " = " << x << "; "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n;
	vii v1, v2, v3, v4;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v1.pb({a,b});
		v2.pb({a, -b});
		v3.pb({-a, b});
		v4.pb({-a, -b});
	}
	sort(v1.bg, v1.nd);
	sort(v2.bg, v2.nd);
	sort(v3.bg, v3.nd);
	sort(v4.bg, v4.nd);
	pii t1, t2, t3, t4;
	t1 = {v1[0].F + v1[n-1].F, v1[0].S + v1[n-1].S};
	t2 = {v2[0].F + v2[n-1].F, v2[0].S + v2[n-1].S};
	t3 = {v3[0].F + v3[n-1].F, v3[0].S + v3[n-1].S};
	t4 = {v4[0].F + v4[n-1].F, v4[0].S + v4[n-1].S};
	bool ans = 0;
	bool b1, b2, b3, b4;
	b1 = b2 = b3 = b4 = 1;
	for(int i = 0; i < n/2; i++){
		pii ti1, ti2, ti3, ti4;
		ti1 = {v1[i].F + v1[n-1-i].F, v1[i].S + v1[n-1-i].S};
		ti2 = {v2[i].F + v2[n-1-i].F, v2[i].S + v2[n-1-i].S};
		ti3 = {v3[i].F + v3[n-1-i].F, v3[i].S + v3[n-1-i].S};
		ti4 = {v4[i].F + v4[n-1-i].F, v4[i].S + v4[n-1-i].S};
		if(ti1 != t1) b1 = 0;
		if(ti2 != t2) b2 = 0;
		if(ti3 != t3) b3 = 0;
		if(ti4 != t4) b4 = 0;
	}
	ans = max(ans, b1);
	ans = max(ans, b2);
	ans = max(ans, b3);
	ans = max(ans, b4);
	if(ans && n%2==0) cout << "possible" << endl;
	else cout << "impossible" << endl;
	
}