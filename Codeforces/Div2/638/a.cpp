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
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v;
        ll tot = 0;
        forn(i, n) {
            v.pb(1ll << (i + 1));
            tot += v[i];
        }
        ll a = 0, b = 0;
        forn(i, sz(v) / 2 - 1) {
            a += v[i];
        }
        a += v[n - 1];
        b = tot - a;
        cout << abs(b - a) << endl;
    }
    return 0;
}