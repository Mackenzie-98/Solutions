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
    int casos = 0;
    while (t--) {
        casos++;
        int x, y;
        string m;
        cin >> x >> y >> m;
        ll ans = 1e18;
        bool ok = 0;
        if (abs(x) + abs(y) == 0) {
            ans = 0;
            ok = 1;
        }
        forn(i, sz(m)) {
            if (m[i] == 'N') {
                y++;
            } else if (m[i] == 'S') {
                y--;
            } else if (m[i] == 'E') {
                x++;
            } else {
                x--;
            }
            if (abs(x) + abs(y) <= i + 1) {
                ans = min(ans, (ll)i + 1);
                ok = 1;
            }
        }
        cout << "Case #" << casos << ": ";
        if (!ok)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}