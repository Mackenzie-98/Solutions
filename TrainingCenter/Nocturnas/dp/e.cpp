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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m;
const int MAX = 105;
ll dp[MAX][MAX];
ll mat[MAX][MAX];
const ll INF = 1e+12;
ll f(int i, int j) {
    if (i > n || j > m) return -INF;
    ll &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = 0;
    ans = max(ans, f(i + 1, j) + mat[i][j]);
    ans = max(ans, f(i, j + 1) + mat[i][j]);
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof dp);
        cin >> n >> m;
        forn(i, n) {
            forn(j, m) {
                cin >> mat[i][j];
            }
        }
        cout << f(0, 0) << endl;
    }
    return 0;
}