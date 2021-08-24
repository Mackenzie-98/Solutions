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
int n;
const int MAX = 1e5 + 5;
ll villas[MAX];
ll cost[MAX];
ll mem[MAX];
ll INF = 1e12;
ll dp(int pos) {
    if (pos < 0) return 0;
    ll &ans = mem[pos];
    if (ans != -1) return ans;
    ans = 0;
    ans = max(ans, dp(pos - 1));
    if (villas[pos] <= pos)
        ans = max(ans, dp(villas[pos] - (pos != 0 ? 1 : 0)) + cost[pos]);
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
        memset(mem, -1, sizeof mem);
        cin >> n;
        forn(i, n) cin >> villas[i];
        forn(i, n) cin >> cost[i];
        cout << dp(n - 1) << endl;
    }
    return 0;
}