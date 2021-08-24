/**
 * @author: Mackenzie
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
const int N = 3e3 + 5;
const int M = 22;
ll m = 1e9 + 7;
ll dp[N][M];
ll add(ll a, ll b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}

ll C(int i, int j) {
    //cout << i << " " << j << endl;
    if (i == j || j == 0 || i == 0) return 1;
    ll &ans = dp[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    ans = add(C(i - 1, j - 1), C(i - 1, j));
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;
    cout << C(2 * m + n - 1, 2 * m) << endl;
    return 0;
}