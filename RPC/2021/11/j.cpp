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
	ll xo, yo, xf, yf;
	ll Xo, Yo, Xf, Yf;
	cin >> xo >> yo >> Xo >> Yo >> xf >> yf >> Xf >> Yf;
	ll d1 = (xo - Xo)*(xo - Xo) + (yo - Yo)*(yo - Yo);
	ll d2 = (xf - Xf)*(xf - Xf) + (yf - Yf)*(yf - Yf);
	ll mx = max(d1, d2);
	double ans = sqrt(mx);
	cout << fixed << setprecision(10) << ans << '\n';
}