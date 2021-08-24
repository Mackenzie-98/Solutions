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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t, n;
    while (cin >> t >> n) {
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        int dp[t + 1];
        for (int i = 0; i <= t; i++) {
            dp[i] = i;
            forn(j, n) {
                if (i - v[j] >= 0) dp[i] = min(dp[i], dp[i - v[j]]);
            }
        }
        cout << dp[t] << endl;
    }
    return 0;
}