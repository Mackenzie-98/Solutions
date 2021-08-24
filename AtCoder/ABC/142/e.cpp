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
const int mx_Pos = 1e3 + 5;
const int mx_Mask = (1 << 13);
const int INF = 1e9;
ll n, m;
ll lim;
vector<int> S;
vector<int> C;
ll memo[mx_Pos][mx_Mask];
ll dp(int pos, int mask) {
    if (pos == m) {
        if (mask == lim)
            return 0;
        else
            return INF;
    }
    ll &ans = memo[pos][mask];
    if (ans != -1) return ans;
    ans = min(dp(pos + 1, mask), dp(pos + 1, mask | S[pos]) + C[pos]);
    return ans;
}

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    memset(memo, -1, sizeof memo);
    cin >> n >> m;
    lim = (1 << n) - 1;
    forn(i, m) {
        ll ci, bi;
        cin >> ci >> bi;
        ll subset = 0;
        forn(i, bi) {
            ll vi;
            cin >> vi;
            subset += (1 << (vi - 1));
        }
        S.pb(subset);
        C.pb(ci);
    }
    ll ans = dp(0, 0);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}