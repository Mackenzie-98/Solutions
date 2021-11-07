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


int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, a, b, year, mcm = oo;
	cin >> k;
	
	
	while(k--){
		cin >> year >> a >> b;
		mcm = min(mcm, year + lcm(a,b));
	}
	
	cout << mcm << endl;
	
	
}