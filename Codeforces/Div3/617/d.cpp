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
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<ll> h(n);
    vector<ll> res;
    forn(i, n) cin >> h[i], (h[i] % (a + b) == 0 ? res.pb(a + b) : res.pb(h[i] % (a + b)));
    sort(all(res));
    ll ans = 0;
    forn(i, n) {
        // cout << res[i] << " ";
        if (res[i] <= a)
            ans++;
        else {
            ll x = (res[i] - 1) / a;
            // cout << x;
            if (k >= x) {
                k -= x;
                ans++;
            }
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}