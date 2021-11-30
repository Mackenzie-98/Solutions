#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define sz size()
#define eps 0.000001
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


ll dp[3010][3010];
int arr[3010];
ll oo = 1e18;
int n;

ll f(int i, int a){
	if(i > n) return -oo;
	if(i == n) return arr[n];
	if(dp[i][a] != -oo) return dp[i][a];
	ll ans = -oo;
	for(int k = 1; k <= a; k++){
		ans = max(ans, f(i+k, k));
	}
	ans += arr[i];
	dp[i][a] = ans;
	return ans;
}


void init(int k){
	for(int i = 0; i <= k+1; i++){
		for(int j = 0; j <= k+1; j++){
			dp[i][j] = -oo;
		}
	}
}

int main() {
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
	cin >> n;
	init(n);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	ll ans = f(1, n);
	cout << ans << endl;
}
