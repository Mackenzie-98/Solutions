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
	int n, B, P, S;
	cin >> n >> B;
	pii arr[n];
	for(int i = 0; i < n; i++){
		cin >> P >> S;
		arr[i] = {P, S};
	}
	long long dp[n + 10][B + 10];
	for(int i = 0; i <= B; i++){
		dp[n][i] = 0;
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= B; j++){
			if(j - arr[i].F >= 0){
				dp[i][j] = max(dp[i+1][j - arr[i].F] + arr[i].S, dp[i+1][j]); 
			}else{
				dp[i][j] = dp[i+1][j];
			}
		}
	}
	cout << dp[0][B] << endl;
}